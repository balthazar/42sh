/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/27 20:52:06 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				st_make_test(t_cmd *cmd1, t_cmd *cmd2)
{
	t_btree			*node1;
	t_btree			*node2;

	printf("\033[0;36m------ BEGIN TEST : [%s %s %s] [%s %s %s]\033[0m\n", cmd1->path, cmd1->cmd[1], cmd1->cmd[2], cmd2->path, cmd2->cmd[1], cmd2->cmd[2]);
	node1 = btree_create_node(cmd1, sizeof(t_cmd));
	node2 = btree_create_node(cmd2, sizeof(t_cmd));
	ft_pipe(node1, node2);
	printf("\033[0;36m------ END TEST\033[0m\n");
}

int					main(void)
{
	st_make_test(
			ft_make_cmd("/bin/ls",  "ls",  "-l", NULL),
			ft_make_cmd("/bin/cat", "cat", "-e", NULL)
			);
	return (0);
}
