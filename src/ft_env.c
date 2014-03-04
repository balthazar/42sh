/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:49:54 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 15:38:27 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static void	ft_null_extra(t_btree *node)
{
	int		i;
	char	**custom_env;
	char	**split;

	i = 2;
	custom_env = NULL;
	while (GETT(node, cmd)[i] && ft_charin(GETT(node, cmd)[i], '='))
	{
		split = ft_strsplit(GETT(node, cmd)[i], '=');
		ft_setenv_b(split[0], split[1], &custom_env);
		ft_free_tab((void ***)&split);
		++i;
	}
	if (!GETT(node, cmd)[i])
		ft_printab(custom_env);
	else
	{
		GETT(node, custom) = custom_env;
		ft_trunc_tab(&GETT(node, cmd), i);
		treat_cmd(node);
	}
}

static void	ft_env_extra(t_btree *node)
{
	int		i;
	char	**custom_env;
	char	**split;

	i = 1;
	custom_env = NULL;
	ft_copy_tab(&custom_env, CTX->env);
	while (GETT(node, cmd)[i] && ft_charin(GETT(node, cmd)[i], '='))
	{
		split = ft_strsplit(GETT(node, cmd)[i], '=');
		ft_setenv_b(split[0], split[1], &custom_env);
		ft_free_tab((void ***)&split);
		++i;
	}
	if (!GETT(node, cmd)[i])
		ft_printab(custom_env);
	else
	{
		GETT(node, custom) = custom_env;
		ft_trunc_tab(&GETT(node, cmd), i);
		treat_cmd(node);
	}
}

void		ft_env(t_btree *node)
{
	if (!GETT(node, cmd)[1])
		ft_printab(CTX->env);
	else if (!CNIL && !ft_charin(GETT(node, cmd)[1], '='))
	{
		ft_trunc_tab(&GETT(node, cmd), 1);
		treat_cmd(node);
	}
	else if (CNIL && !GETT(node, cmd)[2])
		return ;
	else if (CNIL && GETT(node, cmd)[2] && ft_charin(GETT(node, cmd)[2], '='))
		ft_null_extra(node);
	else if (CNIL && GETT(node, cmd)[2] && !ft_charin(GETT(node, cmd)[2], '='))
	{
		ft_trunc_tab(&GETT(node, cmd), 2);
		GETT(node, force_null) = 1;
		treat_cmd(node);
	}
	else if (ft_charin(GETT(node, cmd)[1], '='))
		ft_env_extra(node);
}
