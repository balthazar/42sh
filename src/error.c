/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/02 14:53:32 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

void		ft_exit(int n)
{
	ft_reset_term();
	exit(n);
}

void		ft_error(char *msg)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd("\033[0m", 2);
	ft_exit(1);
}

int			ft_err(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	return (ERR);
}
