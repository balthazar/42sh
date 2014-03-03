/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/03 00:34:25 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				st_del_list(void *content, size_t content_size)
{
	t_elem			*el;

	(void) content_size;
	el = (t_elem *) content;
	ft_memdel((void **) &el->data);
	ft_memdel((void **) &el);
}

void				st_del_simple_list(void *content, size_t content_size)
{
	(void) content_size;
	ft_memdel((void **) content);
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
		ft_lstdel(&cmd->in, st_del_simple_list);
		ft_lstdel(&cmd->out, st_del_simple_list);
		ft_free_tab((void ***) &cmd->cmd);
		ft_memdel((void **) &cmd->path);
	}
	ft_memdel((void **) &cmd);
	ft_memdel((void **) tree);
}

void				ft_clean(t_btree **tree, t_dlist **dlist)
{
	if (tree && *tree)
		st_del_tree(tree);
	if (dlist && *dlist)
		ft_dlstdel(dlist, st_del_list);
}
