/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 11:12:07 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/01 12:42:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			ft_parser_print_err(char c)
{
	ft_putstr("YOLO-SHELL: parse error near '");
	ft_putchar(c);;
	ft_putendl("'");
	return (ERR);
}


int			ft_treat_sep(t_dlist **tmp)
{
	int		ref;
	int		count;
	t_dlist	*list;

	list = *tmp;
	ref = LIST->def;
	count = 0;
	if (LIST->def > 1 && (!list->prev || PREV->def != -1))
		return (ft_parser_print_err(LIST->data[0]));
	count = ft_strlen(LIST->data);
	if ((ref == END && count > 1) || (ref <= 2 && count > 2)
			|| (ref == AND && count != 2))
		return (ft_parser_print_err(LIST->data[0]));
	if (ref == CHEV && !list->next)
		return (ft_parser_print_err(LIST->data[0]));
	*tmp = list->next;
	return (OK);
}

int			ft_lexer_check_err(t_dlist *list)
{
	int		ret;

	ret = OK;
	while (list)
	{
		while (list && LIST->def == -1)
			list = list->next;
		if (list && LIST->def != -1)
			ret = ft_treat_sep(&list);
		if (ret == ERR)
			return (ERR);
	}
	return (ret);
}
