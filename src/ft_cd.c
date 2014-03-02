/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:38:45 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 18:41:33 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "42sh.h"

static void	ft_errors_cd(char *str)
{
	if (errno == 2)
	{
		ft_putstr("CD: No Such File or Directory: ");
		ft_putendl(str);
	}
	else if (errno == 13)
	{
		ft_putstr("CD: Permission Denied: ");
		ft_putendl(str);
	}
}

static void	ft_chdir(t_ctx *ctx, t_btree *node, int *ret)
{
	if (!CMU || !ft_strcmp(CMU, "~"))
		*ret = chdir(ft_getvar_env("HOME", ctx->env));
	else if (CMU && !ft_strcmp(CMU, "-"))
		*ret = chdir(ft_getvar_env("OLDPWD", ctx->env));
	else if (CMU)
		*ret = chdir(CMU);
}

void		ft_cd(t_btree *node)
{
	int		ret;
	t_ctx	*ctx;
	char	*newpwd;

	ctx = ft_get_ctx();
	newpwd = NULL;
	ret = 0;
	if (GETT(node, cmd)[1] && GETT(node, cmd)[2])
		ft_putendl("CD: Too Many Arguments");
	else
	{
		ft_chdir(ctx, node, &ret);
		if (ret == -1 && GETT(node, cmd)[1])
			ft_errors_cd(GETT(node, cmd)[1]);
		else
		{
			ft_setenv_b("OLDPWD", ft_getvar_env("PWD", ctx->env), &ctx->env);
			if (GETT(node, cmd)[1])
				ft_setenv_b("PWD", getcwd(newpwd, LEN1), &ctx->env);
			else
				ft_setenv_b("PWD", getcwd(newpwd, LEN2), &ctx->env);
		}
	}
}
