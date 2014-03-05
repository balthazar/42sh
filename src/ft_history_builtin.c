/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:59:04 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 18:22:29 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

static int	ft_count_history(void)
{
	int		cpt;
	t_ctx	*ctx;
	t_dlist	*tmp;

	ctx = CTX;
	tmp = ctx->history;
	cpt = 0;
	while (tmp)
	{
		++cpt;
		tmp = tmp->next;
	}
	return (cpt);
}

static void	ft_print_hist_from(int number)
{
	t_ctx	*ctx;
	t_dlist	*tmp;
	int		cpt;
	int		len;

	ctx = CTX;
	tmp = ctx->history;
	cpt = 0;
	len = ft_count_history();
	while (tmp)
	{
		if (len <= number)
		{
			ft_putstr("    ");
			ft_putnbr(cpt);
			ft_putstr("  ");
			ft_putendl(tmp->content);
		}
		tmp = tmp->next;
		++cpt;
		--len;
	}
}

static void	ft_print_hist(void)
{
	t_ctx	*ctx;
	t_dlist	*tmp;
	int		cpt;

	ctx = CTX;
	tmp = ctx->history;
	cpt = 0;
	while (tmp)
	{
		ft_putstr("    ");
		ft_putnbr(cpt);
		ft_putstr("  ");
		ft_putendl(tmp->content);
		tmp = tmp->next;
		++cpt;
	}
}

static void	ft_delete_history(void)
{
	t_ctx	*ctx;
	t_dlist	*tmp;
	char	*path;
	int		fd;

	ctx = CTX;
	tmp = ctx->history;
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	free(ctx->history);
	path = ft_getvar_env("HOME", ctx->env);
	if (path)
	{
		path = ft_strjoin(path, "/.yolosh_history");
		fd = open(path, O_TRUNC);
		free(path);
		if (fd != -1)
			close(fd);
	}
	ctx->history = NULL;
	ctx->cur_h = NULL;
	ctx->end_h = NULL;
}

void		ft_history_builtin(t_btree *node)
{
	int		nb;

	if (!GETT(node, cmd[1]))
		ft_print_hist();
	else if (!ft_strcmp(GETT(node, cmd)[1], "-c"))
		ft_delete_history();
	else if (GETT(node, cmd)[1] && GETT(node, cmd)[2])
		ft_err("Too many arguments.");
	else
	{
		if (!ft_stronly(GETT(node, cmd)[1], ft_isdigit))
			ft_err("Numeric argument required.");
		else
		{
			nb = ft_atoi(GETT(node, cmd)[1]);
			if (nb >= 0)
				ft_print_hist_from(nb);
			else
				ft_err("Invalid argument.");
		}
	}
}
