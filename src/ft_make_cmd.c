/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/27 20:51:23 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

t_cmd				*ft_make_cmd(char *path, char *e1, char *e2, char *e3)
{
	t_cmd			*cmd;

	if (!(cmd = (t_cmd *) malloc(sizeof(t_cmd))))
		ft_error("Can't malloc 'cmd'");
	cmd->type = CMD;
	cmd->path = path;
	if (!(cmd->cmd = (char **) malloc(sizeof(char *))))
		ft_error("Can't malloc 'cmd->cmd'");
	cmd->cmd[0] = e1;
	cmd->cmd[1] = e2;
	cmd->cmd[2] = e3;
	cmd->cmd[3] = NULL;
	cmd->env = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->fail = FALSE;
	return (cmd);
}
