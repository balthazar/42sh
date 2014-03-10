/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:52:21 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/10 16:24:34 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_join_three(char *one, char *two, char *three)
{
	char	*join;
	char	*final;

	join = ft_strjoin(one, two);
	if (one)
		free(one);
	final = ft_strjoin(join, three);
	if (join)
		free(join);
	if (three)
		free(three);
	return (final);
}

void	ft_streplace(char **str, char *pattern, char *replace)
{
	size_t	i;
	size_t	len;
	char	*first;
	char	*end;

	i = 0;
	len = ft_strlen(pattern);
	while (*str && pattern && (*str)[i] != '\0')
	{
		end = NULL;
		if (!ft_strncmp(pattern, *str + i, len))
		{
			first = (i > 0) ? ft_strsub(*str, 0, i) : NULL;
			end = ft_strsub(*str, i + len, ft_strlen(*str + i + len));
			free(*str);
			*str = ft_join_three(first, replace, end);
			i += ft_strlen(replace);
		}
		else
			++i;
	}
}
