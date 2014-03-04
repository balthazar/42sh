/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 11:12:07 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/04 16:15:16 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			ft_parser_print_err(char c)
{
	char	*tmp;
	char	*tmp2;
	char	ch[2];

	ch[0] = c;
	ch[1] = '\0';
	tmp = ft_strjoin("Parse error near '", ch);
	tmp2 = ft_strjoin(tmp, "'");
	ft_memdel((void **) &tmp);
	ft_err(tmp2);
	ft_memdel((void **) &tmp2);
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
