/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/28 22:50:02 by mpillet          ###   ########.fr       */
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

	ft_create_files(node);
	return (p[C(node)->type](node));
}
