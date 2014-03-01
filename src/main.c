/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/01 18:29:05 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

int					main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	setup_signal();
	ft_get_ctx()->env = env;
	ft_term_init();
	ft_prompt();
	ft_reset_term();
	/*ft_test("ls -l | cat -e > toto && cat toto | wc -l | cat -e > titi ; cat titi ; rm titi toto");
	ft_test("ls -l > LOL | wc -l ; rm LOL");
	printf("%s\n", );*/
	return (0);
}
