/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:11 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 12:28:48 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

void	ft_reset_line(t_ctx *ctx)
{
	int		i;

	ft_clean_line();
	ft_bzero(ctx->line, LINE_LEN);
	ft_strcpy(ctx->line, ctx->cur_h->content);
	i = ft_strlen(ctx->line);
	ctx->i = i;
	ctx->len = i;
	ft_putstr(ctx->line);
}

void	ft_add_history(char *str)
{
	int		fd;
	char	*tmp;
	t_ctx	*ctx;
	t_dlist	*new;

	ctx = CTX;
	new = ft_dlstnew(str, sizeof(char) * (ft_strlen(str) + 1));
	ft_dlstpush(&ctx->history, new);
	/*if (ctx->current)
	{
	  free(ctx->current);
	  ctx->current = NULL;
	}*/
	ctx->cur_h = NULL;
	ctx->end_h = new;
	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_CREAT | O_WRONLY | O_APPEND, 0604);
		free(tmp);
		if (fd == -1)
			ft_err("Can't open your history file.");
		else
		{
			ft_putendl_fd(str, fd);
			close(fd);
		}
	}
}

void	ft_load_history(t_ctx *ctx)
{
	int		fd;
	char	*tmp;
	t_dlist	*new;

	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_RDONLY);
		free(tmp);
		if (fd != -1)
		{
			while (get_next_line(fd, &tmp))
			{
				new = ft_dlstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1));
				ft_dlstpush(&ctx->history, new);
				free(tmp);
			}
			ctx->end_h = new;
			ctx->cur_h = NULL;
			free(tmp);
			close(fd);
		}
		else
			ft_err("Your history will reset after this session.");
	}
	else
		ft_err("Your history will reset after this session.");
}
