/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:37:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/07 17:23:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				print_pids(void)
{
	t_list			*list;

	list = CTX->jobs;
	if (!list)
		printf("LIST IS NULL\n");
	while (list)
	{
		printf("----------------------------------------\n");
		printf("PID [%d]\n", ((t_jobs *)list->content)->pid);
		printf("First or not  [%d]\n", ((t_jobs *)list->content)->first);
		printf("NB [%d]\n", ((t_jobs *)list->content)->nb);
		printf("----------------------------------------\n");
		list = list->next;
	}
}

int					ft_launch(t_btree *tree, t_dlist *dlist)
{
	ft_reset_term();
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
	ft_clean(&tree, &dlist);
	ft_clear_line();
	ft_raw_term();
	ft_aff_prompt();
	return (OK);
}
