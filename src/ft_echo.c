/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:46:16 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 18:36:22 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_echo(t_btree *node)
{
	int		i;

	i = 1;
	while (GETT(node, cmd)[i])
	{
		if (i > 1)
			ft_putchar(' ');
		ft_putstr(GETT(node, cmd)[i]);
		++i;
	}
	ft_putchar('\n');
}
