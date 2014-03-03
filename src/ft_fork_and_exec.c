/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:24:03 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/01 19:19:00 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include "42sh.h"

void				ft_fork_and_exec(t_btree *node)
{
	pid_t			father;

	if (-1 == (father = fork()))
		ft_error("fork failed");
	else if (!father)
		ft_exec(node);
	wait(NULL);
}
