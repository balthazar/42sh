/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:55:03 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 10:56:30 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_free_tab(void ***arr)
{
	int				i;

	i = 0;
	while (arr && *arr && (*arr)[i])
	{
		if ((*arr)[i])
			ft_memdel((void **)&(*arr)[i]);
		++i;
	}
	if (arr)
		ft_memdel((void **)arr);
}
