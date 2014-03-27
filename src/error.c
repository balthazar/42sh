/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/12 17:57:43 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "norme42sh.h"

void		ft_exit(int n)
{
	if (CTX->jobs)
		ft_putendl_fd("Error: There are jobs open.", 2);
	else
	{
		ft_reset_term();
		exit(n);
	}
}

void		ft_error(char *msg)
{
	ft_err(msg);
	ft_exit(1);
}

int			ft_err(char *msg)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Yolosh: Error: ", 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd("\033[0m", 2);
	return (ERR);
}
