/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:59:04 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/10 16:27:42 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

static void	ft_history_error(void)
{
	ft_err("Usage: history [-c] [-d offset] [n] or history -anrw [filename]");
}

static int	ft_parse_history_cmd(char *str, t_btree *node)
{
	if (str && ft_strlen(str) >= 2 && str[0] == '-')
	{
		if (ft_indexof(str + 1, '-') != -1)
			ft_history_error();
		else
		{
			if (ft_indexof(str, 'a') != -1)
				ft_append_new_history(GETT(node, cmd)[2], CTX);
			else if (ft_indexof(str, 'n') != -1)
				ft_get_newlines(GETT(node, cmd)[2], CTX, -1);
			else if (ft_indexof(str, 'r') != -1)
				ft_save_newlines(GETT(node, cmd)[2], CTX);
			else if (ft_indexof(str, 'w') != -1)
				ft_write_history(GETT(node, cmd)[2], CTX);
			return (1);
		}
	}
	return (0);
}

static void	ft_parse_history(t_btree *node)
{
	int		nb;

	if (ft_parse_history_cmd(GETT(node, cmd)[1], node))
		;
	else if (GETT(node, cmd)[1] && GETT(node, cmd)[2])
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
	else if (GETT(node, cmd)[1] && GETT(node, cmd)[2] && GETT(node, cmd)[3])
		ft_err("Too many arguments.");
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
