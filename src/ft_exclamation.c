/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclamation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:50:13 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 18:01:03 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

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
