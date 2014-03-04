/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/04 15:36:00 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "42sh.h"

int					ft_exec(t_btree *node)
{
	if (GETT(node, force_null))
		execve(C(node)->path, C(node)->cmd, NULL);
	else if (GETT(node, custom))
		execve(C(node)->path, C(node)->cmd, C(node)->custom);
	else
		execve(C(node)->path, C(node)->cmd, C(node)->env);
	return (0);
}
