/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:59:04 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 19:38:36 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void	ft_history_error(void)
{
	ft_err("history: usage: history [-c] [-d offset] [n] or history -anrw [filename]");
}

static void	ft_parse_history(t_btree *node)
{
	int		nb;

	if (GETT(node, cmd)[1] && GETT(node, cmd)[2])
		ft_err("Too many arguments.");
	else
	{
		if (!ft_stronly(GETT(node, cmd)[1], ft_isdigit))
			ft_err("Numeric argument required.");
		else
		{
			nb = ft_atoi(GETT(node, cmd)[1]);
			if (nb >= 0)
				ft_print_hist_from(nb);
			else
				ft_err("Invalid argument.");
		}
	}
}

void		ft_history_builtin(t_btree *node)
{
	if (!GETT(node, cmd[1]))
		ft_print_history();
	else if (!ft_strcmp(GETT(node, cmd)[1], "-c"))
		ft_delete_history(CTX);
	else if (!ft_strcmp(GETT(node, cmd)[1], "-d"))
	{
		if (GETT(node, cmd)[2])
			ft_delete_specific_history(CTX, ft_atoi(GETT(node, cmd)[2]), 0);
		else
			ft_history_error();
	}
	else
		ft_parse_history(node);
}
