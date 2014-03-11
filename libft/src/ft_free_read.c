/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 14:51:43 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/11 14:58:48 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void		ft_free_read(t_read **read)
{
	t_read	*tmp;
	t_read	*next;

	tmp = *read;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void **)&tmp->read);
		ft_memdel((void **)&tmp);
		tmp = next;
	}
	*read = NULL;
}
