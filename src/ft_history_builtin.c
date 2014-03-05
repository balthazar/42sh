/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:59:04 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 16:18:28 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_history_builtin(t_btree *node)
{
	int		nb;

	if (!GETT(node, cmd[1]))
		ft_print_hist();
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

char		*ft_return_specific(char *str)
{
	t_ctx	*ctx;
	t_dlist	*tmp;
	int		nb;
	int		cpt;

	if (str && str[0] != '\0')
	{
		ctx = CTX;
		cpt = 0;
		tmp = ctx->history;
		nb = ft_atoi(str);
		free(str);
		while (tmp)
		{
			if (cpt == nb)
				return (tmp->content);
			++cpt;
			tmp = tmp->next;
		}
	}
	ft_err("No such event.");
	return (NULL);
}
