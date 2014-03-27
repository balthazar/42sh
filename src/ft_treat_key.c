/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:22:32 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 11:18:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

static void			st_assign(t_key keys[])
{
	keys[0].key = K_ENTER;
	keys[0].fn = treat_key_enter;
	keys[1].key = K_LEFT;
	keys[1].fn = treat_key_left;
	keys[2].key = K_RIGHT;
	keys[2].fn = treat_key_right;
	keys[3].key = K_CTRLD;
	keys[3].fn = treat_key_ctrld;
	keys[4].key = K_DELETE;
	keys[4].fn = treat_key_delete;
	keys[5].key = K_DOWN;
	keys[5].fn = treat_key_down;
	keys[6].key = K_UP;
	keys[6].fn = treat_key_up;
	keys[7].key = K_HOME;
	keys[7].fn = treat_key_home;
	keys[8].key = K_END;
	keys[8].fn = treat_key_end;
	keys[9].key = K_BACKSP;
	keys[9].fn = treat_key_backsp;
}

int					ft_treat_key(char *buf)
{
	int				i;
	static t_key	keys[NB_KEYS];

	st_assign(keys);
	i = 0;
	while (i < NB_KEYS)
	{
		if (keys[i].key && 0 == ft_strcmp(keys[i].key, buf))
			return (keys[i].fn());
		++i;
	}
	return (ERR);
}
