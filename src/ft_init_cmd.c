/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 10:26:55 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/07 10:28:31 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void		ft_init_cmd(t_cmd *cmd)
{
	cmd->path = NULL;
	cmd->cmd = NULL;
	cmd->env = ft_get_env();
	cmd->custom = NULL;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->fail = FALSE;
	cmd->force_null = 0;
}
