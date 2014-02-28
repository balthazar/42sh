/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/28 23:40:20 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char				*get_type(int type)
{
	if (CMD == type)
		return ("CMD");
	else if (PIPE == type)
		return ("PIPE");
	else if (AND == type)
		return ("&&");
	else if (END == type)
		return (";");
	return ("UNKNOWN");
}

void				print_tree(t_btree *node, int level, int dir)
{
	int				tmp;
	int				i;

	tmp = level;
	if (node)
	{
		print_tree(node->left, level + 1, 1);
		while (tmp)
		{
			printf("    ");
			--tmp;
		}
		if (dir == 1)
			printf("\033[34mL \033[0m");
		else if (dir == 2)
			printf("\033[34mR \033[0m");
		if (level == 0)
		{
			printf("\033[34m\\ \033[0m");
		}
		else
		{
			printf("\033[37m%s\033[0m", get_type(C(node)->type));
		}
		if (CMD == C(node)->type)
		{
			printf("\033[35m");
			i = 0;
			while (C(node)->cmd[i])
			{
				printf(" %s", C(node)->cmd[i]);
				++i;
			}
			printf("\033[0m");
		}
		printf("\n");
		print_tree(node->right, level + 1, 2);
	}
}
