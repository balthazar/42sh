/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:37:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/04 19:25:04 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "42sh.h"

static int			ft_replacements(char *str)
{
	int		i;
	int		cpt;
	char	*first;
	char	*last;
	char	*rep;

	i = 0;
	while (str && str[i])
	{
		cpt = 0;
		first = NULL;
		last = NULL;
		if (str[i] == '!')
		{
			while (str[i + cpt] != ' ')
				++cpt;
			rep = ft_return_specific(ft_struntil(str + i + 1, " "));
			first = ft_strsub(str, 0, i);
			last = ft_strsub(str, i + cpt, ft_strlen(str) - i - cpt);
			printf("pute '%s' '%s' '%s'\n", first, last, rep);
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
	if (ft_has_char(CTX->line) && ft_replacements(CTX->line))
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
