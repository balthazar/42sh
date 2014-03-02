/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:37:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/03 00:28:41 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	ft_lstdel(&cmd->in, st_del_simple_list);
	ft_lstdel(&cmd->out, st_del_simple_list);
	ft_free_tab((void ***) &cmd->cmd);
	ft_memdel((void **) &cmd->path);
	ft_memdel((void **) &cmd);
	ft_memdel((void **) tree);
}

void				st_try_del(t_btree **tree, t_dlist **dlist)
{
	if (tree && *tree)
		st_del_tree(tree);
	if (dlist && *dlist)
		ft_dlstdel(dlist, st_del_list);
}

int					ft_launch(t_btree *tree, t_dlist *dlist)
{
	ft_reset_term();
	ft_putchar('\n');
	CTX->prompt = 0;
	if (ft_has_char(CTX->line))
	{
		ft_lexer(CTX->line, &dlist);
		if (OK == ft_lexer_check_err(dlist))
		{
			ft_parser(&dlist, &tree);
			ft_treat_node(tree);
		}
	}
	st_try_del(&tree, &dlist);
	ft_bzero(ft_get_ctx()->line, LINE_LEN);
	CTX->i = 0;
	ft_raw_term();
	ft_aff_prompt();
	return (OK);
}
