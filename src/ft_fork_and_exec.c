/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:24:03 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/04 17:00:18 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "42sh.h"

void				ft_fork_and_exec(t_btree *node)
{
	pid_t			father;
	int				status;

	if (-1 == (father = fork()))
		ft_error("fork failed");
	else if (!father)
	{
		if ((signal(SIGTSTP, SIG_DFL) == SIG_ERR))
			ft_error("signal error");
		ft_exec(node);
	}
	CTX->child = father;
	waitpid(father, &status, WUNTRACED);
}
