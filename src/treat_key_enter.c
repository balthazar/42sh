/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_enter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:00:23 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/04 12:43:44 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static int			is_full_cmd(char *line)
{
	int				i;

	i = ft_strlen(line) - 1;
	while (i > 1 && line[i] == ' ')
		--i;
	return (!(line[i] == '&' && line[i - 1] == '&')
			&& !(line[i] == '|') && ft_odd_quotes(line));
}

int					treat_key_enter(void)
{
	if (is_full_cmd(CTX->line))
	{
		if (ft_strcmp(CTX->line, ""))
			ft_add_history(CTX->line);
		ft_launch(NULL, NULL);
		CTX->prompt = 0;
	}
	else if (ft_is_valid(CTX->line))
	{
		if (!ft_odd_quotes(CTX->line))
			ft_add_char('\n');
		ft_putstr("> ");
	}
	else
	{
		//don't think we need to add here
		//ft_add_history(CTX->line);
		ft_bzero(CTX->line, LINE_LEN);
		CTX->i = 0;
		ft_clear_line();
		ft_aff_prompt();
	}
	return (OK);
}
