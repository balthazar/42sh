/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:12:47 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/04 14:52:21 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include <term.h>
#include "42sh.h"

int					ft_putput(int c)
{
	write(1, &c, 1);
	return (0);
}

void				ft_term_init(void)
{
	char		*term;

	if ((term = (char *) getenv("TERM")) == NULL)
		ft_error("Can't determinate terminal.\n");
	if (tgetent(NULL, term) != 1)
		ft_error("Failed with tgetent\n");
	ft_raw_term();
}

void				ft_reset_term(void)
{
	struct termios		tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | IEXTEN);
	tattr.c_iflag |= (BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	tattr.c_cflag |= (CSIZE | PARENB);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgetstr("ke", NULL), 1, ft_putput);
}

void				ft_raw_term(void)
{
	struct termios		tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	tattr.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	tattr.c_cflag &= ~(CSIZE | PARENB);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tputs(tgetstr("ks", NULL), 1, ft_putput);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
