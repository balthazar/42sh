/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:12:47 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/01 16:18:08 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "42sh.h"

void			ft_term_init(void)
{
	char		*term;

	if ((term = (char *) getenv("TERM")) == NULL)
		ft_error("Can't determinate terminal.\n");
	if (tgetent(NULL, term) != 1)
		ft_error("Failed with tgetent\n");
	ft_raw_term();
}
