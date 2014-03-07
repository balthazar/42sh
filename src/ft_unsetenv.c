/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:30:41 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 16:22:54 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static int	ft_notin(char *str, t_btree *node)
{
	int		i;
	char	*tmp;

	i = 1;
	while (node && GETT(node, cmd)[i])
	{
		tmp = ft_strjoin(GETT(node, cmd)[i], "=");
		if (!ft_strncmp(tmp, str, ft_strlen(tmp)))
		{
			free(tmp);
			return (0);
		}
		++i;
		free(tmp);
	}
	return (1);
}

static int	ft_count_unset(t_ctx *ctx, t_btree *node)
{
	char	*tmp;
	int		i;
	int		j;
	int		cpt;

	i = 1;
	cpt = 0;
	while (node && GETT(node, cmd)[i])
	{
		j = 0;
		tmp = ft_strjoin(GETT(node, cmd)[i], "=");
		while (ctx->env[j])
		{
			if (!ft_strncmp(tmp, ctx->env[j], ft_strlen(tmp)))
				++cpt;
			++j;
		}
		++i;
		free(tmp);
	}
	return (cpt);
}

static void	ft_unsetenv_aux(char ***new, t_btree *node, t_ctx *ctx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ctx->env && ctx->env[i])
	{
		if (ft_notin(ctx->env[i], node))
		{
			(*new)[j] = ft_strdup(ctx->env[i]);
			++j;
		}
		++i;
	}
	(*new)[j] = NULL;
	ft_free_tab((void ***)&ctx->env);
}

void		ft_unsetenv(t_btree *node)
{
	char	**new;
	t_ctx	*ctx;
	int		len;

	if (!GETT(node, cmd)[1])
		return ;
	ctx = CTX;
	len = ft_tab_len(ctx->env) + 1 - ft_count_unset(ctx, node);
	new = (char **) malloc(sizeof(char *) * len);
	ft_unsetenv_aux(&new, node, ctx);
	ctx->env = new;
}

void		ft_rmline_tab(char *value, char ***arr, int len)
{
	char	**new;
	char	*tmp;
	int		i;
	int		j;

	if (!value || !arr)
		return ;
	i = 0;
	j = 0;
	len = ft_tab_len(*arr);
	new = (char **) malloc(sizeof(char *) * (len + 1));
	tmp = ft_strjoin(value, "=");
	while (*arr && (*arr)[i])
	{
		if (ft_strncmp((*arr)[i], tmp, ft_strlen(tmp)))
		{
			new[j] = ft_strdup((*arr)[i]);
			++j;
		}
		++i;
	}
	new[j] = NULL;
	ft_free_tab((void ***)arr);
	free(tmp);
	*arr = new;
}
