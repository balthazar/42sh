/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:38:47 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 18:27:32 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static t_built	*ft_get_builts(void)
{
	static t_built	*builts = NULL;

	if (!builts)
	{
		if (!(builts = (t_built *) malloc(sizeof(t_built) * (NBBS + 1))))
			ft_error("Can't malloc 'builts'");
		builts[NBBS].name = NULL;
		builts[0].name = "cd";
		builts[0].fn = &ft_cd;
		builts[1].name = "exit";
		builts[1].fn = &ft_exit_builtin;
		builts[2].name = "env";
		builts[2].fn = &ft_env;
		builts[3].name = "setenv";
		builts[3].fn = &ft_setenv;
		builts[4].name = "unsetenv";
		builts[4].fn = &ft_unsetenv;
		builts[5].name = "echo";
		builts[5].fn = &ft_echo;
	}
	return (builts);
}

void			ft_exec_builtin(t_btree *node)
{
	t_built		*builts;

	builts = ft_get_builts();
	while ((*builts).name)
	{
		if (GETT(node, cmd) && !ft_strcmp((*builts).name, GETT(node, cmd)[0]))
			(*builts).fn(node);
		++builts;
	}
}

int				ft_detect_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "setenv")
		|| !ft_strcmp(cmd, "unsetenv")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}
