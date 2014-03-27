/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 22:12:42 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 10:59:51 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printlst(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		ft_putstr("[");
		ft_putnbr(i);
		ft_putstr("] '");
		ft_putstr((char *)lst->content);
		ft_putendl("'");
		lst = lst->next;
		i++;
	}
}
