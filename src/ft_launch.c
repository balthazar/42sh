/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:37:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/05 17:49:29 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

static int		ft_string_rep(char **str, int i, int cpt, int *len)
{
	char	*first;
	char	*last;
	char	*rep;

	if ((*str)[i] == '!')
		rep = ft_return_specific(ft_struntil_fn((*str) + i + 1, ft_isalpha));
	else
		rep = ft_getvar_env(ft_struntil_fn((*str) + i + 1, ft_isalpha), ENV);
	if (!rep && (*str)[i] == '!')
		return (-1);
	*len = ft_strlen(rep);
	first = ft_strsub(*str, 0, i);
	last = ft_strsub(*str, i + cpt, ft_strlen(*str) - i - cpt);
	*str = ft_multijoin(2, first, rep, last);
	if (first)
		free(first);
	if (last)
		free(last);
	return (1);
}

static int		ft_replacements(char *str, t_ctx *ctx, int i)
{
	int		cpt;
	int		len;

	while (str && str[i])
	{
		cpt = 0;
		if (str[i] == '!' || str[i] == '$')
		{
			while (str[i + cpt] != ' ')
				++cpt;
			if (ft_string_rep(&str, i, cpt, &len) == -1)
				return (0);
			if (str)
			{
				ft_bzero(ctx->line, LINE_LEN);
				ft_strcpy(ctx->line, str);
				free(str);
				break ;
			}
		}
		++i;
	}
	if ((int)ft_strlen(str) > i + len)
		ft_replacements(ctx->line, ctx, i + len);
	return (1);
}

int				ft_launch(t_btree *tree, t_dlist *dlist)
{
	ft_reset_term();
	ft_putchar('\n');
	CTX->prompt = 0;
	if (ft_replacements(CTX->line, CTX, 0) && ft_has_char(CTX->line))
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
