/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:22:32 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/06 00:57:29 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					ft_treat_key(char *buf)
{
	int				i;
	t_key			keys[NB_KEYS] =
	{
		{ K_ENTER, treat_key_enter },
		{ K_LEFT, treat_key_left },
		{ K_RIGHT, treat_key_right },
		{ K_CTRLD, treat_key_ctrld },
		{ K_DELETE, treat_key_delete },
		{ K_DOWN, treat_key_down },
		{ K_UP, treat_key_up },
		{ K_BACKSP, treat_key_backsp }
	};

	i = 0;
	while (i < NB_KEYS)
	{
		if (0 == ft_strcmp(keys[i].key, buf))
			return (keys[i].fn());
		++i;
	}
	return (ERR);
}
