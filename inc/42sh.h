/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:11:13 by janteuni          #+#    #+#             */
/*   Updated: 2014/02/27 20:08:38 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 42SH_H
# define 42SH_H
# include "libft.h"

#include <stdio.h> /* TODO delete */

# define CHEV	1
# define PIPE	2
# define END	3
# define AND	4
# define STR	-1
# define CMD	0

# define ERR	-1
# define OK		0

# define TRUE	1
# define FALSE	0

# define OP_S	1
# define OP_D	2

# define LIST	((t_elem *)list->content)
# define PREV	((t_elem *)list->prev->content)
# define NEXT	((t_elem *)list->next->content)

/*# define D_TREE	(((t_cmd *)tree->data)->type)
# define D_NODE	(((t_cmd *)node->data)->type)
# define RIGHT	(((t_cmd *)tree->right->data)->type)*/


# define D_NODE	((t_cmd *)first->content)->type
# define D_TREE	((t_cmd *)node->content)->type
# define RIGHT	((t_cmd *)first->right->content)
# define LEFT	((t_cmd *)first->left->content)

typedef struct	s_elem
{
	char		*data;
	int			def;
}				t_elem;

typedef struct	s_chev
{
	int			op;
	char		*file;
}				t_chev;

typedef struct	s_cmd
{
	int			type;
	char		*path;
	char		**cmd;
	char		**env;
	t_list		*in;
	t_list		*out;
	int			fail;
}				t_cmd;

void			ft_lexer(char *str, t_dlist **list);
int				ft_lexer_check_err(t_dlist *list);
void			ft_parser(t_dlist **list, t_btree **tree);
void			add_node(t_btree **tree, void *data, size_t content_size);
#endif /* !42SH_H */
