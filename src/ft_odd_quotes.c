/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odd_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 15:12:53 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/02 15:18:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			ft_odd_quotes(char *line)
{
	int		i;

	i = 0;
	while (*line)
	{
		if (*line == '"')
			++i;
		++line;
	}
	return (i % 2 == 0);
}
