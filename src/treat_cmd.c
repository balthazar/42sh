/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/27 12:37:03 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "norme42sh.h"

static int			st_dot(int c)
{
	return ((char)c == '.');
}

int					treat_cmd(t_btree *node)
{
	if (!((t_cmd *)(node)->content)->cmd)
		return (OK);
	if (ft_stronly(((t_cmd *)(node)->content)->cmd[0], st_dot))
		return (OK);
	if (ft_detect_builtin(GETT(node, cmd)[0]))
		ft_exec_builtin(node);
	else
	{
		if (ERR == ft_redirect(node) || ERR == ft_fill_path(C(node)))
			C(node)->fail = TRUE;
		else
			ft_fork_and_exec(node);
	}
	return (OK);
}
