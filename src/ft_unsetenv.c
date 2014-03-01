/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:30:41 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 18:52:55 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static void	ft_unsetenv_init(t_ctx **ctx, int *i, int *len)
{
	*i = 0;
	*ctx = ft_get_ctx();
	*len = ft_tab_len((*ctx)->env);
}

void		ft_unsetenv(t_btree *node)
{
	char	**new;
	t_ctx	*ctx;
	int		i;
	int		len;

//	if (GETT(node, cmd)[1] && GETT(node, cmd[2]))
//		ft_err("Too many arguments.");
	if ((GETT(node, cmd)[1] && GETT(node, cmd[2])) || (!GETT(node, cmd)[1]))
		return ;
	ft_unsetenv_init(&ctx, &i, &len);
	new = (char **) malloc(sizeof(char *) * (len + 1));
	while (*ctx->env)
	{
		if (ft_strncmp(*ctx->env, ft_strjoin(GETT(node, cmd)[1], "="),
						ft_strlen(GETT(node, cmd)[1]) + 1))
		{
			new[i] = *ctx->env;
			i++;
		}
		ctx->env++;
	}
	new[i] = NULL;
	ctx->env = new;
}

void		ft_unsetenv_b(char *name, char ***env)
{
	char	**new;
	int		i;
	int		len;

	if (!name)
		return ;
	i = 0;
	len = ft_tab_len(*env);
	new = (char **) malloc(sizeof(char *) * (len + 1));
	while (*env && **env)
	{
		if (ft_strncmp(**env, ft_strjoin(name, "="), ft_strlen(name) + 1))
		{
			new[i] = **env;
			i++;
		}
		(*env)++;
	}
	new[i] = NULL;
	*env = new;
}
