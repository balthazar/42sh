/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:00:17 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/02 18:43:12 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "42sh.h"

char	*ft_time_majd(struct tm *l)
{
	char	str[32];
	char	*out;

	strftime(str, 32, "%g-%m-%d", l);
	out = ft_strdup(str);
	return (out);
}

char	*ft_time_majw(struct tm *l)
{
	char	str[32];
	char	*out;

	strftime(str, 32, "%D", l);
	out = ft_strdup(str);
	return (out);
}

char	*ft_time_majt(struct tm *l)
{
	char	str[32];
	char	*out;

	strftime(str, 32, "%R", l);
	out = ft_strdup(str);
	return (out);
}
