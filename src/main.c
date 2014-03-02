/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/02 18:52:18 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

int					main(int ac, char **av, char **env)
{
	t_ctx	*ctx;

	(void) ac;
	(void) av;
	ctx = CTX;
	ft_copy_tab(&ctx->env, env);
	if (!(ctx->psone = (t_psone *) malloc(sizeof(t_psone))))
		ft_error("Can't malloc 'PS1 utility'");
	PS->str = NULL;
	ft_term_init();
	ft_prompt();
	ft_reset_term();
	return (0);
}
