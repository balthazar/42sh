/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:11 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/10 19:22:16 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

void		ft_reset_line(t_ctx *ctx, int flag)
{
	ft_clean_line();
	ft_bzero(ctx->line, LINE_LEN);
	if (flag == 1 && ctx->cur_h)
		ft_strcpy(ctx->line, ctx->cur_h->content);
	else if (flag == 2)
		ft_strcpy(ctx->line, ctx->save);
	ctx->len = ft_strlen(ctx->line);
	ctx->i = 0;
	ft_rewrite(TRUE);
}

static char	*ft_replace_newline(char *str)
{
	char	*out;

	out = ft_strdup(str);
	ft_streplace(&out, "\n", " ");
	return (out);
}

void		ft_add_history(char *str)
{
	int		fd;
	char	*tmp;
	char	*copy;
	t_ctx	*ctx;
	t_dlist	*new;

	ctx = CTX;
	copy = ft_replace_newline(str);
	new = ft_dlstnew(copy, sizeof(char) * (ft_strlen(str) + 1));
	ft_dlstpush(&ctx->history, new);
	ctx->cur_h = NULL;
	ctx->end_h = new;
	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_WRONLY | O_APPEND | O_CREAT, 0604);
		free(tmp);
		if (fd != -1)
		{
			ft_putendl_fd(copy, fd);
			close(fd);
		}
	}
	free(copy);
}

void		ft_load_history(t_ctx *ctx, int fd, char *tmp, t_dlist *new)
{
	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_RDONLY | O_CREAT, 0604);
		free(tmp);
		if (fd != -1)
		{
			while (get_next_line(fd, &tmp))
			{
				new = ft_dlstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1));
				ft_dlstpush(&ctx->history, new);
				free(tmp);
				++ctx->cpt_h;
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
