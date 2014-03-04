/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:57:52 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/04 15:34:31 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

void			print_cmd(t_cmd *cmd)
{
	int			i;

	i = 0;
	ft_putstr("TYPE:");
	ft_putnbr(cmd->type);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("CMD:");
	if (cmd->cmd)
	{
		while (cmd->cmd[i] != '\0')
		{
			ft_putendl(cmd->cmd[i]);
			i++;
		}
	}
	ft_putchar('\n');
	if (cmd->out)
	{
		ft_putendl("OUT:");
		while (cmd->out)
		{
			ft_putendl(((t_chev *)cmd->out->content)->file);
			ft_putnbr(((t_chev *)cmd->out->content)->op);
			ft_putchar('\n');
			cmd->out = cmd->out->next;
		}
	}
	if (cmd->in)
	{
		ft_putendl("IN:");
		while (cmd->in)
		{
			ft_putendl(((t_chev *)cmd->in->content)->file);
			ft_putnbr(((t_chev *)cmd->in->content)->op);
			ft_putchar('\n');
			cmd->in = cmd->in->next;
		}
	}
}


void			ft_fill_redirection(t_cmd *cmd, t_dlist *list)
{
	t_chev		chev;
	int			op;

	if (LIST->data[1] == '<' || LIST->data[1] == '>')
		op = OP_D;
	else
		op = OP_S;
	chev.op = op;
	chev.file = ft_strdup(NEXT->data);
	if (LIST->data[0] == '<')
		ft_lstpush(&cmd->in, ft_lstnew(&chev, sizeof(t_chev)));
	else
		ft_lstpush(&cmd->out, ft_lstnew(&chev, sizeof(t_chev)));

}

static void		init_safe(t_cmd *cmd)
{
	cmd->path = NULL;
	cmd->cmd = NULL;
	cmd->env = ft_get_env();
	cmd->custom = NULL;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->fail = FALSE;
	cmd->force_null = 0;
}

static void		create_and_push_cmd(t_dlist *list, int index, t_cmd *cmd, t_btree **tr)
{
	int			k;

	k = 0;
	while (index)
	{
		if (LIST->def == CHEV)
		{
			ft_fill_redirection(cmd, list);
			list = list->next;
			index--;
		}
		else if (LIST->def == STR)
		{
			cmd->cmd[k] = ft_strdup(LIST->data);
			k++;
		}
		index--;
		list = list->next;
	}
	if (cmd->cmd)
		cmd->cmd[k] = NULL;
	cmd->type = CMD;
	add_node(tr, cmd, sizeof(t_cmd));
}

static void		create_and_push_sep(t_dlist *list, t_btree **tree)
{
	t_cmd		cmd;

	init_safe(&cmd);
	if (LIST->def == PIPE)
	{
		if (LIST->data[1] == '|')
			cmd.type = OR;
		else
			cmd.type = PIPE;
	}
	else
		cmd.type = LIST->def;
	add_node(tree, &cmd, sizeof(t_cmd));
}

static void		ft_count_cmd(t_dlist *tmp, int index, t_btree **tree)
{
	int			str;
	int			chev;
	int			i;
	t_dlist		*list;
	t_cmd		cmd;

	init_safe(&cmd);
	list = tmp;
	chev = 0;
	str = 0;
	i = index;
	while (index)
	{
		if (LIST->def == CHEV)
			chev++;
		else if (LIST->def == STR)
			str++;
		list = list->next;
		index--;
	}
	if (str > 0)
		str = str - chev;
	if (str > 0)
		cmd.cmd = (char **)malloc(sizeof(char *) * str + 1);
	create_and_push_cmd(tmp, i, &cmd, tree);
}

void				ft_parser(t_dlist **split, t_btree **tree)
{
	t_dlist		*list;
	t_dlist		*tmp;
	int				index;

	list = *split;
	while (list)
	{
		tmp = list;
		index = 0;
		while (list && LIST->def <= 1)
		{
			index++;
			list = list->next;
		}
		ft_count_cmd(tmp, index, tree);
		if (list && LIST->def > 1)
		{
			create_and_push_sep(list, tree);
			list = list->next;
		}
	}
}
