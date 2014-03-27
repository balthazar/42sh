/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_enter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:00:23 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 10:51:27 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static int			is_full_cmd(char *line)
{
	int				i;

	i = ft_strlen(line) - 1;
	while (i > 1 && line[i] == ' ')
		--i;
	return (!(line[i] == '&' && line[i - 1] == '&')
	&& !(line[i] == '|') && ft_odd_quotes(line));
}

static void			st_treat_subshell(t_ctx *ctx)
{
	ctx->sub_shell = 1;
	ft_insert_char('\n');
	ft_putstr("> ");
	ctx->prompt_len = 2;
	ctx->pos.x = 2;
	ctx->pos.y = 0;
}

int					treat_key_enter(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (is_full_cmd(ctx->line))
	{
		if (ft_strcmp(ctx->line, ""))
			ft_add_history(ctx->line);
		ft_launch(NULL, NULL);
		ctx->prompt = 0;
	}
	else if (ft_is_valid(ctx->line))
		st_treat_subshell(ctx);
	else
	{
		if (ft_strcmp(ctx->line, ""))
			ft_add_history(ctx->line);
		ft_bzero(ctx->line, LINE_LEN);
		ctx->i = 0;
		ft_clear_line();
		ft_aff_prompt();
	}
	return (OK);
}
