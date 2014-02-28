/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/28 23:42:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_test(char *line)
{
	static int		num = 0;
	t_btree			*tree;
	t_dlist			*dlist;
	t_ctx			*ctx;

	ctx = ft_get_ctx();
	tree = NULL;
	dlist = NULL;
	ft_lexer(line, &dlist);
	ft_parser(&dlist, &tree);
	printf("\033[34m[TEST %02d]\033[0m \033[35m\"%s\"\033[0m\n", num++, line);
	printf("\n");
	print_tree(tree, 0, 0);
	printf("\n");
	ft_treat_node(tree);
	printf("\n");
}
