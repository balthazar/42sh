/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:49:54 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 18:45:49 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

void		ft_copyenv(char ***dest, char **env)
{
	int		i;
	int		len;

	i = 0;
	if (!env)
		return ;
	len = ft_tab_len(env);
	*dest = (char **) malloc(sizeof(char *) * (len + 1));
	while (env && *env)
	{
		(*dest)[i] = *env;
		i++;
		env++;
	}
	(*dest)[i] = NULL;
}

static void	ft_print_env(char **env)
{
	t_ctx	*ctx;
	int		i;

	i = 0;
	if (!env)
	{
		ctx = ft_get_ctx();
		while (ctx->env && ctx->env[i])
		{
			ft_putendl(ctx->env[i]);
			i++;
		}
	}
	else
	{
		while (env && env[i])
		{
			ft_putendl(env[i]);
			i++;
		}
	}
}

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
		++i;
	}
	if (!GETT(node, cmd)[i])
		ft_print_env(customenv);
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
	ft_copyenv(&customenv, ft_get_ctx()->env);
	while (GETT(node, cmd)[i] && ft_charin(GETT(node, cmd)[i], '='))
	{
		split = ft_strsplit(GETT(node, cmd)[i], '=');
		ft_setenv_b(split[0], split[1], &customenv);
		++i;
	}
	if (!GETT(node, cmd)[i])
		ft_print_env(customenv);
//	else
//		ft_redirect(node, customenv);
}

void		ft_env(t_btree *node)
{
	if (!GETT(node, cmd)[1])
		ft_print_env(NULL);
//	else if (NMI && !ft_charin(GETT(node, cmd)[1], '='))
//		ft_redirect(node, ft_get_ctx()->env);
	else if (!NMI && !GETT(node, cmd)[2])
		return ;
	else if (!NMI && GETT(node, cmd)[2] && ft_charin(GETT(node, cmd)[2], '='))
		ft_env_null_extra(node);
//	else if (!NMI && GETT(node, cmd)[2] && !ft_charin(GETT(node, cmd)[2], '='))
//		ft_redirect(node, NULL);
	else if (ft_charin(GETT(node, cmd)[1], '='))
		ft_env_extra(node);
}
