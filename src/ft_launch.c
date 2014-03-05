/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:37:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/05 12:45:51 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

static char			*ft_string_rep(char *str, int i, int cpt, int flag)
{
	char	*out;
	char	*first;
	char	*last;
	char	*rep;

	rep = NULL;
	out = NULL;
	if (flag == 1)
		rep = ft_return_specific(ft_struntil(str + i + 1, ' '));
	else if (flag == 2)
		rep = ft_strdup(ft_getvar_env(ft_struntil(str + i + 1, ' '), CTX->env));
	if (rep)
	{
		first = ft_strsub(str, 0, i);
		last = ft_strsub(str, i + cpt, ft_strlen(str) - i - cpt);
		out = ft_multijoin(2, first, rep, last);
		free(rep);
		if (first)
			free(first);
		if (last)
			free(last);
	}
	return (out);
}

static int			ft_replacements(char *str, t_ctx *ctx)
{
	int		i;
	int		cpt;

	i = 0;
	while (str && str[i])
	{
		cpt = 0;
		if (str[i] == '!')
		{
			while (str[i + cpt] != ' ')
				++cpt;
			str = ft_string_rep(str, i, cpt, 1);
			if (str)
			{
				ft_bzero(ctx->line, LINE_LEN);
				ft_strcpy(ctx->line, str);
				free(str);
			}
		}
		if (str[i] == '$')
		{
			while (str[i + cpt] != ' ')
				++cpt;
			str = ft_string_rep(str, i, cpt, 2);
			if (str)
			{
				ft_bzero(ctx->line, LINE_LEN);
				ft_strcpy(ctx->line, str);
				free(str);
			}
		}
		++i;
	}
	return (1);
}

int					ft_launch(t_btree *tree, t_dlist *dlist)
{
	ft_reset_term();
	ft_putchar('\n');
	CTX->prompt = 0;
	if (ft_replacements(CTX->line, CTX) && ft_has_char(CTX->line))
	{
		ft_lexer(CTX->line, &dlist);
		if (OK == ft_lexer_check_err(dlist))
		{
			ft_parser(&dlist, &tree);
			ft_treat_node(tree);
		}
	}
	ft_clean(&tree, &dlist);
	ft_clear_line();
	ft_raw_term();
	ft_aff_prompt();
	return (OK);
}
