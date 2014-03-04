/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 12:28:31 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/02 18:43:02 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "42sh.h"

static t_stime	*ft_gethandlers(void)
{
	static t_stime	*out = NULL;

	if (!out)
	{
		if (!(out = (t_stime *) malloc(sizeof(t_stime) * (NBTIME + 1))))
			ft_error("Can't malloc time pointer functions array.");
		out[NBTIME].type = NULL;
		out[0].type = "%D";
		out[0].fn = ft_time_majd;
		out[1].type = "%W";
		out[1].fn = ft_time_majw;
		out[2].type = "%w";
		out[2].fn = ft_time_w;
		out[3].type = "%*";
		out[3].fn = ft_time_star;
		out[4].type = "%T";
		out[4].fn = ft_time_majt;
		out[5].type = "%t";
		out[5].fn = ft_time_twelve;
		out[6].type = "%@";
		out[6].fn = ft_time_twelve;
	}
	return (out);
}

void			ft_timepurpose(t_ctx *ctx)
{
	time_t		t;
	struct tm	*l;
	char		*tmp;
	t_stime		*handlers;

	tmp = NULL;
	t = time(NULL);
	l = localtime(&t);
	handlers = ft_gethandlers();
	while ((*handlers).type)
	{
		tmp = (*handlers).fn(l);
		ft_streplace(&PS->str, (*handlers).type, tmp);
		free(tmp);
		++handlers;
	}
}

char			*ft_time_w(struct tm *l)
{
	char	str[32];
	char	*out;

	strftime(str, 32, "%a%e", l);
	out = ft_strdup(str);
	return (out);
}

char			*ft_time_star(struct tm *l)
{
	char	str[32];
	char	*out;

	strftime(str, 32, "%T", l);
	out = ft_strdup(str);
	return (out);
}

char			*ft_time_twelve(struct tm *l)
{
	char	str[32];
	char	*out;

	strftime(str, 32, "%l:%M%p", l);
	out = ft_strdup(str);
	return (out);
}
