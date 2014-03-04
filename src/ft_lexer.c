/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:18:31 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/02 14:57:04 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void		ft_push_elem(char *data, char c, t_dlist **list)
{
	t_elem	elem;

	elem.data = data;
	elem.def = is_sep(c);
	ft_dlstpush(list, ft_dlstnew(&elem, sizeof(t_elem)));
}

int			ft_push_quote(char *line, int i, t_dlist **list)
{
	int		start;

	start = i;
	i++;
	while (line[i] != '\0' && QUOTE != is_sep(line[i]))
		i++;
	if (i - 1 - start == 0)
		ft_push_elem(ft_strnew(0), 'a', list);
	else
		ft_push_elem(ft_strsub(line, start + 1, i - 1 - start), 'a', list);
	return (i - start + 1);
}

int			ft_push_sep(char *line, int i, t_dlist **list)
{
	int	 	start;

	start = i;
	if (QUOTE == is_sep(line[i]))
		return (ft_push_quote(line, i, list));
	while (line[i] == line[start])
		i++;
	ft_push_elem(ft_strsub(line, start, i - start), line[start], list);
	return (i - start);
}

int			ft_push_char(char *line, int i, t_dlist **list)
{
	int	 	start;

	start = i;
	while (line[i] != '\0' && is_sep(line[i]) < 0)
		i++;
	ft_push_elem(ft_strsub(line, start, i - start), line[start], list);
	return (i - start);
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
