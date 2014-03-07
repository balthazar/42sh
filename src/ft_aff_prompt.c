/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/07 17:06:37 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_aff_prompt(void)
{
	if (CTX->prompt)
		return ;
	ft_putstr("YOLO-Shell> ");
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	CTX->prompt = 1;
}
