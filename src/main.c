/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/27 10:47:37 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "norme42sh.h"

int					main(int ac, char **av, char **env)
{
	t_ctx	*ctx;

	ctx = CTX;
	(void)ac;
	(void)av;
	ctx = CTX;
	ft_term_init();
	setup_signal();
	ft_copy_tab(&ctx->env, env);
	ft_load_history(ctx, 0, NULL, NULL);
	ft_aff_prompt();
	ft_loop();
	ft_reset_term();
	return (0);
}
