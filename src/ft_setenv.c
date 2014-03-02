/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:31:20 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/02 17:35:38 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static void	ft_setenv_aux(char ***new, t_btree *node, t_ctx *ctx)
{
	int		i;

	i = 0;
	while (ctx->env && ctx->env[i])
	{
		(*new)[i] = ft_strdup(ctx->env[i]);
		++i;
	}
	(*new)[i] = ft_multijoin(2, GETT(node, cmd)[1], "=", GETT(node, cmd)[2]);
	(*new)[i + 1] = NULL;
	ft_free_tab((void ***)&ctx->env);
}

void		ft_setenv(t_btree *node)
{
	char	**new;
	t_ctx	*ctx;
	int		len;

	if (!GETT(node, cmd)[1])
		ft_env(node);
	//else if (GETT(node, cmd)[1] && GETT(node, cmd)[2] && GETT(node, cmd)[3])
	//	ft_err("Too many arguments");
	else
	{
		ctx = CTX;
		len = ft_tab_len(ctx->env);
		ft_rmline_tab(GETT(node, cmd)[1], &ctx->env);
		new = (char **) malloc(sizeof(char *) * (len + 2));
		ft_setenv_aux(&new, node, ctx);
		ctx->env = new;
	}
}

void		ft_setenv_b(char *name, char *value, char ***env)
{
	char	**new;
	int		i;
	int		len;

	if (!name)
	{
		ft_env(NULL);
		return ;
	}
	i = 0;
	len = ft_tab_len(*env);
	ft_rmline_tab(name, env);
	new = (char **) malloc(sizeof(char *) * (len + 2));
	while (*env && (*env)[i])
	{
		new[i] = ft_strdup((*env)[i]);
		++i;
	}
	new[i] = ft_multijoin(2, name, "=", value);
	new[i + 1] = NULL;
	ft_free_tab((void ***)env);
	*env = new;
}
