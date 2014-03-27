/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:45:30 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/01 18:50:00 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "norme42sh.h"

int					ft_get_fd(void)
{
	static int		fd = -1;

	if (fd == -1)
	{
		fd = open("/dev/tty", O_RDWR);
		if (fd == -1)
		{
			ft_error("failed to open /dev/tty");
		}
	}
	return (fd);
}
