/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_backsp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/03 15:08:37 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int				treat_key_backsp(void)
{
	if (CTX->i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putput);
		tputs(tgetstr("dc", NULL), 1, ft_putput);
		--CTX->i;
		ft_del_char();
	}
	return (OK);
}
