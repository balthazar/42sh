/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 10:42:27 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 19:27:31 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

void	ft_exit_builtin(t_btree *node)
{
	int		nb;

	nb = 0;
	if (GETT(node, cmd)[1])
		nb = ft_atoi(GETT(node, cmd)[1]);
	ft_exit(nb);
}
