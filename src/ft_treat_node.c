/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/03 13:09:28 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					ft_treat_node(t_btree *node)
{
	static int		(*p[6]) (t_btree *) = {
		treat_cmd,
		treat_chev,
		treat_pipe,
		treat_end,
		treat_and,
		treat_or
	};

	if (ft_create_files(node) == ERR)
	{
		C(node)->fail = TRUE;
		return (ERR);
	}
	p[C(node)->type](node);
	ft_close_files(node);
	return (OK);
}
