/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/27 10:50:08 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

void				st_del_list(void *content, size_t content_size)
{
	t_elem			*el;

	(void)content_size;
	el = (t_elem *)content;
	ft_memdel((void **)&el->data);
	ft_memdel((void **)&el);
}

void				st_del_simple_list(t_list **alist)
{
	t_list			*ptr;
	t_list			*next;
	t_chev			*ch;

	if (*alist)
	{
		ptr = *alist;
		while (ptr)
		{
			next = ptr->next;
			ch = (t_chev *)ptr->content;
			ft_memdel((void **)&ch->file);
			ft_memdel((void **)&ch);
			ft_memdel((void **)&ptr);
			ptr = next;
		}
	}
}

void				st_del_tree(t_btree **tree)
{
	t_cmd			*cmd;

	if ((*tree)->left)
		st_del_tree(&((*tree)->left));
	if ((*tree)->right)
		st_del_tree(&((*tree)->right));
	cmd = (*tree)->content;
	if (cmd->type == CMD)
	{
		st_del_simple_list(&cmd->in);
		st_del_simple_list(&cmd->out);
		ft_free_tab((void ***)&cmd->cmd);
		ft_memdel((void **)&cmd->path);
	}
	ft_memdel((void **)&cmd);
	ft_memdel((void **)tree);
}

void				ft_clean(t_btree **tree, t_dlist **dlist)
{
	if (tree && *tree)
		st_del_tree(tree);
	if (dlist && *dlist)
		ft_dlstdel(dlist, st_del_list);
}
