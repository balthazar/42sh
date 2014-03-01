/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:48:19 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/01 19:00:14 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					ft_is_valid(char *line)
{
	t_dlist			*dlist;

	dlist = NULL;
	ft_putchar('\n');
	if (ft_has_char(line))
	{
		ft_lexer(line, &dlist);
		return (OK == ft_lexer_check_err(dlist));
	}
	return (TRUE);
}
