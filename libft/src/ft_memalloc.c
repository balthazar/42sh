/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:43:56 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 10:57:17 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	if (size)
	{
		mem = (void *)malloc(size);
		if (mem)
			ft_bzero(mem, size);
	}
	return (mem);
}
