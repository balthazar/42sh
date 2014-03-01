/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:31:20 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 18:57:53 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static void	ft_setenv_init(t_ctx **ctx, int *i, int *len)
{
	*i = 0;
	*ctx = ft_get_ctx();
	*len = ft_tab_len((*ctx)->env);
}

void		ft_setenv(t_btree *node)
{
	char	**new;
	t_ctx	*ctx;
	int		i;
	int		len;

	if (!GETT(node, cmd)[1])
		ft_env(node);
//	if (GETT(node, cmd)[1] && GETT(node, cmd)[2] && GETT(node, cmd)[3])
//		ft_err("Too many arguments.");
	if ((GETT(node, cmd)[1] && GETT(node, cmd)[2] && GETT(node, cmd)[3])
		|| (!GETT(node, cmd)[1]))
		return ;
	ft_setenv_init(&ctx, &i, &len);
	ft_unsetenv_b(GETT(node, cmd)[1], &ctx->env);
	new = (char **) malloc(sizeof(char *) * (len + 2));
	while (*ctx->env)
	{
		new[i] = *ctx->env;
		i++;
		ctx->env++;
	}
	new[i] = ft_multijoin(2, GETT(node, cmd)[1], "=", GETT(node, cmd)[2]);
	new[i + 1] = NULL;
	ctx->env = new;
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
	ft_unsetenv_b(name, env);
	new = (char **) malloc(sizeof(char *) * (len + 2));
	while (*env && **env)
	{
		new[i] = **env;
		i++;
		(*env)++;
	}
	new[i] = ft_multijoin(2, name, "=", value);
	new[i + 1] = NULL;
	*env = new;
}
