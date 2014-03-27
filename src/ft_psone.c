/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:38:51 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/27 11:27:05 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include "norme42sh.h"

static void	ft_crealsize(int *i, int *size, int open)
{
	++(*i);
	*size -= (open) ? 1 : 0;
}

static int	ft_realsize(char *str, int i, int open, int size)
{
	while (str[i])
	{
		if (!ft_strncmp(str + i, "%{", 2))
		{
			if (open)
				return (-1);
			open = 1;
			size -= 2;
			i += 2;
		}
		else if (!ft_strncmp(str + i, "%}", 2))
		{
			if (!open)
				return (-1);
			open = 0;
			size -= 2;
			i += 2;
		}
		else
			ft_crealsize(&i, &size, open);
	}
	if (open)
		return (-1);
	return (size);
}

static void	ft_replacements(t_ctx *ctx, char **env, char *tmp)
{
	char			hostname[1024];
	struct passwd	*p;

	p = getpwuid(getuid());
	if (p)
		ft_streplace(&PS->str, "%n", p->pw_name);
	gethostname(hostname, 1023);
	ft_streplace(&PS->str, "%M", hostname);
	tmp = ft_struntil(hostname, '.');
	ft_streplace(&PS->str, "%m", tmp);
	free(tmp);
	tmp = ft_strdup(ft_getvar_env("PWD", env));
	ft_streplace(&PS->str, "%/", tmp);
	ft_streplace(&tmp, ft_getvar_env("HOME", env), "~");
	ft_streplace(&tmp, "/Volumes/Data", "");
	ft_streplace(&PS->str, "%~", tmp);
	free(tmp);
	ft_streplace(&PS->str, "%%", "%");
	ft_streplace(&PS->str, "%)", ")");
	tmp = ft_strdup(ft_getvar_env("SHLVL", env));
	ft_streplace(&PS->str, "%L", tmp);
	free(tmp);
	ft_timepurpose(ctx);
}

void		ft_psone(char **env, t_ctx *ctx)
{
	char	*copy;

	copy = ft_getvar_env("PS1", env);
	if (PS->str)
		ft_memdel((void **)&PS->str);
	if (copy)
	{
		PS->str = ft_strdup(copy);
		ft_replacements(ctx, env, NULL);
		if ((PSLEN = ft_realsize(PS->str, 0, 0, ft_strlen(PS->str))) == -1)
		{
			ft_memdel((void **)&PS->str);
			PS->str = ft_strdup("YOLO-Shell> ");
			PS->realsize = ft_strlen(PS->str);
			return ;
		}
		ft_streplace(&PS->str, "%{", "");
		ft_streplace(&PS->str, "%}", "");
	}
	else
	{
		PS->str = ft_strdup("YOLO-Shell> ");
		PS->realsize = ft_strlen(PS->str);
	}
}
