/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:37:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/02 17:31:25 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					ft_launch(void)
{
	t_btree			*tree;
	t_dlist			*dlist;

	ft_reset_term();
	tree = NULL;
	dlist = NULL;
	ft_putchar('\n');
	CTX->prompt = 0;
	if (ft_has_char(CTX->line))
	{
		ft_lexer(CTX->line, &dlist);
		if (OK == ft_lexer_check_err(dlist))
		{
			ft_parser(&dlist, &tree);
			ft_treat_node(tree);
		}
	}
	ft_bzero(ft_get_ctx()->line, LINE_LEN);
	CTX->i = 0;
	ft_raw_term();
	ft_aff_prompt();
	return (OK);
}
