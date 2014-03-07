/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:18:31 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/07 10:22:05 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			is_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	if (c == '<' || c == '>')
		return (CHEV);
	if (c == '|')
		return (PIPE);
	if (c == ';')
		return (END);
	if (c == '&')
		return (AND);
	if (c == '"')
		return (QUOTE);
	return (-1);
}

void		ft_lexer(char *line, t_dlist **list)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (is_sep(line[i]) > 0)
			i = i + ft_push_sep(line, i, list);
		else if (is_sep(line[i]) == -1)
			i = i + ft_push_char(line, i, list);
		else
			i++;
	}
}
