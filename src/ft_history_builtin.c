/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:59:04 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 19:16:20 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

static void	ft_delete_history(t_ctx *ctx)
{
	t_dlist	*tmp;
	t_dlist	*swap;
	char	*path;
	int		fd;

	tmp = ctx->history;
	while (tmp)
	{
		swap = tmp;
		tmp = tmp->next;
		free(swap->content);
		free(swap);
	}
	path = ft_getvar_env("HOME", ctx->env);
	if (path)
	{
		path = ft_strjoin(path, "/.yolosh_history");
		fd = open(path, O_TRUNC);
		free(path);
		if (fd != -1)
			close(fd);
	}
	ctx->history = NULL;
	ctx->cur_h = NULL;
	ctx->end_h = NULL;
}

static void	ft_delete_specific_history(t_ctx *ctx, char *str)
{
	t_dlist	*tmp;
	t_dlist	*swap;
	int		nb;
	int		cpt;

	cpt = 0;
	nb = ft_atoi(str);
	tmp = ctx->history;
	while (tmp)
	{
		if (cpt == nb)
		{
			swap = tmp;
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			free(swap->content);
			free(swap);
			break ;
		}
		tmp = tmp->next;
		++cpt;
	}
	ctx->cur_h = NULL;
}

void		ft_history_builtin(t_btree *node)
{
	int		nb;

	if (!GETT(node, cmd[1]))
		ft_print_history();
	else if (!ft_strcmp(GETT(node, cmd)[1], "-c"))
		ft_delete_history(CTX);
	else if (!ft_strcmp(GETT(node, cmd)[1], "-d"))
		ft_delete_specific_history(CTX, GETT(node, cmd)[2]);
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
