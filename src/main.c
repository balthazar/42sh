/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/02 23:00:41 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

int					main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	setup_signal();
	ft_copy_tab(&ft_get_ctx()->env, env);
	ft_term_init();
	ft_aff_prompt();
	ft_loop();
	ft_reset_term();
	return (0);
}
