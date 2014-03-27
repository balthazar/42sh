/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 11:01:11 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/11 15:00:08 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "norme42sh.h"

void	ft_append_new_history(char *filename, t_ctx *ctx)
{
	int		fd;
	int		i;
	t_dlist	*tmp;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0604);
	if (fd != -1)
	{
		i = 0;
		tmp = ctx->history;
		while (tmp)
		{
			if (i >= ctx->cpt_h)
				ft_putendl_fd(tmp->content, fd);
			tmp = tmp->next;
			++i;
		}
		close(fd);
	}
	else
		ft_err("Can't write current session lines into this file.");
}

void	ft_write_history(char *filename, t_ctx *ctx)
{
	int		fd;
	t_dlist	*tmp;

	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0604);
	if (fd != -1)
	{
		tmp = ctx->history;
		while (tmp)
		{
			ft_putendl_fd(tmp->content, fd);
			tmp = tmp->next;
		}
		close(fd);
	}
	else
		ft_err("Can't write history into this file.");
}

void	ft_get_newlines(char *filename, t_ctx *ctx, int fdsave)
{
	int		fd;
	char	*tmp;
	t_dlist	*new;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		new = NULL;
		get_next_line(-1, NULL, 1);
		while (get_next_line(fd, &tmp, 0) > 0)
		{
			if (fdsave != -1)
				ft_putendl_fd(tmp, fdsave);
			new = ft_dlstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1));
			ft_dlstpush(&ctx->history, new);
			free(tmp);
		}
		if (new)
			ctx->end_h = new;
		ctx->cur_h = NULL;
		free(tmp);
		close(fd);
	}
	else
		ft_err("Can't open this file.");
}

void	ft_save_newlines(char *filename, t_ctx *ctx)
{
	char	*tmp;
	int		fd;

	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_WRONLY | O_APPEND | O_CREAT, 0604);
		free(tmp);
		if (fd != -1)
		{
			ft_get_newlines(filename, ctx, fd);
			close(fd);
		}
		else
		{
			ft_get_newlines(filename, ctx, -1);
			ft_err("Can't save newlines into your history file.");
		}
	}
	else
	{
		ft_get_newlines(filename, ctx, -1);
		ft_err("You've unset some variables, you're a real hacker...");
	}
}
