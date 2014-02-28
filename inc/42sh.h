#ifndef A42SH_H
# define A42SH_H
# include "libft.h"

#include <stdio.h> /* TODO delete */

# define CHEV		1
# define PIPE		2
# define END		3
# define AND		4
# define STR		-1
# define CMD		0

# define ERR		-1
# define OK			0

# define TRUE		1
# define FALSE		0

# define OP_S		1
# define OP_D		2

# define LIST		((t_elem *)list->content)
# define PREV		((t_elem *)list->prev->content)
# define NEXT		((t_elem *)list->next->content)

# define D_NODE		((t_cmd *)first->content)->type
# define D_TREE		((t_cmd *)node->content)->type
# define RIGHT		((t_cmd *)first->right->content)
# define LEFT		((t_cmd *)first->left->content)

# define C(EL)		((t_cmd *) EL->content)

typedef struct		s_ctx
{
	char			**env;
}					t_ctx;

typedef struct		s_elem
{
	char			*data;
	int				def;
}					t_elem;

typedef struct		s_chev
{
	int				op;
	char			*file;
}					t_chev;

typedef struct		s_cmd
{
	int				type;
	char			*path;
	char			**cmd;
	char			**env;
	t_list			*in;
	t_list			*out;
	int				fail;
}					t_cmd;

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Commons
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

char				**ft_get_env(void);
t_ctx				*ft_get_ctx(void);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Parser / Lexer
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_lexer(char *str, t_dlist **list);
int					ft_lexer_check_err(t_dlist *list);
void				ft_parser(t_dlist **list, t_btree **tree);
void				add_node(t_btree **tree, void *data, size_t content_size);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Exec
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_fork_and_exec(t_btree *node);
int					ft_exec(t_btree *node);
int					ft_fill_path(t_cmd *cmd);
int					ft_pipe(t_btree *node1, t_btree *node2);
t_cmd				*ft_make_cmd(char *path, char *e1, char *e2, char *e3, char **env);
int					ft_treat_node(t_btree *node);
int					ft_redirect(t_btree *node);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Error
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_error(char *msg);

#endif /* !A42SH_H */
