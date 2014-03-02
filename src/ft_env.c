/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:49:54 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/02 16:52:21 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static void	ft_env_null_extra(t_btree *node)
{
	int		i;
	char	**customenv;
	char	**split;

	i = 2;
	customenv = NULL;
	while (GETT(node, cmd)[i] && ft_charin(GETT(node, cmd)[i], '='))
	{
		split = ft_strsplit(GETT(node, cmd)[i], '=');
		ft_setenv_b(split[0], split[1], &customenv);
		ft_free_tab((void ***)&split);
		++i;
	}
	if (!GETT(node, cmd)[i])
		ft_printab(customenv);
//	else
//		ft_redirect(node, customenv);
}

static void	ft_env_extra(t_btree *node)
{
	int		i;
	char	**customenv;
	char	**split;

	i = 1;
	customenv = NULL;
	ft_copy_tab(&customenv, CTX->env);
	while (GETT(node, cmd)[i] && ft_charin(GETT(node, cmd)[i], '='))
	{
		split = ft_strsplit(GETT(node, cmd)[i], '=');
		ft_setenv_b(split[0], split[1], &customenv);
		ft_free_tab((void ***)&split);
		++i;
	}
	if (!GETT(node, cmd)[i])
		ft_printab(customenv);
//	else
//		ft_redirect(node, customenv);
}

void		ft_env(t_btree *node)
{
	if (!GETT(node, cmd)[1])
		ft_printab(CTX->env);
//	else if (NMI && !ft_charin(GETT(node, cmd)[1], '='))
//		ft_redirect(node, CTX->env);
	else if (!NMI && !GETT(node, cmd)[2])
		return ;
	else if (!NMI && GETT(node, cmd)[2] && ft_charin(GETT(node, cmd)[2], '='))
		ft_env_null_extra(node);
//	else if (!NMI && GETT(node, cmd)[2] && !ft_charin(GETT(node, cmd)[2], '='))
//		ft_redirect(node, NULL);
	else if (ft_charin(GETT(node, cmd)[1], '='))
		ft_env_extra(node);
}
