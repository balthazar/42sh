/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/01 18:25:40 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "42sh.h"

int					ft_exec(t_btree *node)
{
	if (ft_detect_builtin(GETT(node, cmd)[0]))
	{
		ft_exec_builtin(node);
		//t[ft_get_type()](node);
	}
	else
		execve(C(node)->path, C(node)->cmd, C(node)->env);
	return (0);
}
