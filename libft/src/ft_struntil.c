/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:43:36 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/05 11:49:13 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_struntil(char *str, char stop)
{
	int		i;

	i = 0;
	if (ft_indexof(str, stop) == -1)
		return (ft_strdup(str));
	while (str && str[i])
	{
		if (str[i] == stop)
			return (ft_strsub(str, 0, i));
		++i;
	}
	return (NULL);
}
