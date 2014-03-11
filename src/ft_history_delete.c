/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 11:01:11 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 23:34:49 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

void		ft_delete_history(t_ctx *ctx)
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

void		ft_delete_specific_history(t_ctx *ctx, int nb, int cpt)
{
	t_dlist	*tmp;
	t_dlist	*swap;

	tmp = ctx->history;
	while (tmp && nb >= 0)
	{
		if (cpt == nb)
		{
			swap = tmp;
			ctx->history = (tmp == ctx->history) ? ctx->history->next : HIS;
			ctx->end_h = (tmp == ctx->end_h) ? ctx->end_h->prev : ctx->end_h;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			free(swap->content);
			free(swap);
			break ;
		}
		tmp = tmp->next;
		++cpt;
	}
	if (cpt < nb || nb < 0)
		ft_err("History position out of range.");
	ctx->cur_h = NULL;
}
