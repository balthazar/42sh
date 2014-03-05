/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:46:29 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 18:53:44 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

int			ft_count_history(void)
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

static void	ft_print_spaces(int cpt, int len)
{
	char	*tmp;
	size_t	lenmax;
	size_t	lencpt;

	tmp = ft_itoa(len);
	lenmax = ft_strlen(tmp);
	free(tmp);
	tmp = ft_itoa(cpt);
	lencpt = ft_strlen(tmp);
	free(tmp);
	while (lencpt < lenmax)
	{
		ft_putchar(' ');
		++lencpt;
	}
}

void		ft_print_history(void)
{
	t_ctx	*ctx;
	t_dlist	*tmp;
	int		cpt;
	int		len;

	ctx = CTX;
	cpt = 0;
	tmp = ctx->history;
	len = ft_count_history();
	while (tmp)
	{
		ft_print_spaces(cpt, len);
		ft_putnbr(cpt);
		ft_putstr("  ");
		ft_putendl(tmp->content);
		tmp = tmp->next;
		++cpt;
	}
}

void		ft_print_hist_from(int number)
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
			ft_print_spaces(cpt, len);
			ft_putnbr(cpt);
			ft_putstr("  ");
			ft_putendl(tmp->content);
		}
		tmp = tmp->next;
		++cpt;
		--len;
	}
}
