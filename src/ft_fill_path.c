/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:04:21 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/02 15:07:38 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <unistd.h>

static int		ft_check_access(char *path)
{
	if (!path)
		return (-1);
	if (access(path, F_OK) != -1)
	{
		if (access(path, X_OK) != -1)
			return (1);
		else
			ft_putendl_fd("Error: Permission denied", 2);
		return (0);
	}
	ft_putendl_fd("Error: No such file or directory ", 2);
	return (-1);
}

static char		**ft_get_paths(char **env)
{
	int			i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (ft_strsplit(env[i] + 5, ':'));
		i++;
	}
	ft_putendl_fd("Error: No path variable in environment", 2);
	return (NULL);
}

static void		ft_check_paths(t_cmd *cmd, char **paths)
{
	int			i;
	char		*try;

	i = 0;
	while (paths[i])
	{
		try = ft_multijoin(2, paths[i], "/", cmd->cmd[0]);
		if (access(try, F_OK) != -1)
		{
			if (access(try, X_OK) != -1)
				cmd->path = try;
			else
				ft_putendl_fd("Error: Permission denied", 2);
			break ;
		}
		ft_memdel((void **)&try);
		i++;
	}
}

static int		st_err_cmd(char *name)
{
	char		*tmp;

	tmp = ft_strjoin(name, ": command not found");
	ft_err(tmp);
	ft_memdel((void **) &tmp);
	return (ERR);
}

int				ft_fill_path(t_cmd *cmd)
{
	char		**paths;
	int			i;

	i = 0;
	if (0 == ft_strcmp(cmd->cmd[0], ""))
		return (st_err_cmd(cmd->cmd[0]));
	if (ft_strchr(cmd->cmd[0], '/'))
	{
		if (ft_check_access(cmd->cmd[0]) == 1)
		{
			cmd->path = ft_strdup(cmd->cmd[0]);
			return (OK);
		}
		return (ERR);
	}
	if (!(paths = ft_get_paths(cmd->env)))
		return (ERR);
	ft_check_paths(cmd, paths);
	ft_free_tab((void ***)&paths);
	if (!cmd->path)
		return (st_err_cmd(cmd->cmd[0]));
	return (OK);
}

