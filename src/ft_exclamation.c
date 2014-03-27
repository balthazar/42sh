/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclamation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:50:13 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 18:28:12 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "norme42sh.h"

int			ft_isexcl(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c) || c == '-')
		return (1);
	return (0);
}

char		*ft_return_specific(char *str)
{
	t_ctx	*ctx;
	t_dlist	*tmp;
	int		nb;
	int		cpt;

	if (str && str[0] != '\0' && ft_stronly(str, ft_isdigit))
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
