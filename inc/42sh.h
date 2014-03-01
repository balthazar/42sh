#ifndef A42SH_H
# define A42SH_H

# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"

#include <stdio.h> /* TODO delete */

# define BUF_LEN	6
# define LINE_LEN	2048

# define CTX		ft_get_ctx()

# define CMD		0
# define CHEV		1
# define PIPE		2
# define END		3
# define AND		4
# define OR			5
# define STR		-1

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
# define CH(X)		(((t_chev *)X->content))

/*
** Insanes Defines
*/
# define GETT(E, T)	((t_cmd *) (E)->content)->T
# define CMU		(GETT(node, cmd)[1])
# define PS			ctx->psone
# define NBTIME		7
# define NBBS		6
# define LEN1		(ft_strlen(GETT(node, cmd)[1]) + 15)
# define LEN2		(ft_strlen(ft_getvar_env("HOME", ctx->env)) + 15)
# define NMI		(ft_strcmp(GETT(node, cmd)[1], "-i"))

typedef struct		s_ctx
{
	char			**env;
	char			line[LINE_LEN];
	int				i;
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

typedef struct		s_built
{
	char			*name;
	void			(*fn)();
}					t_built;

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Testing
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void		ft_test(char *line);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Commons
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

char		**ft_get_env(void);
t_ctx		*ft_get_ctx(void);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Termcaps
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

int			ft_putput(int c);
void		ft_reset_term(void);
void		ft_raw_term(void);
void		ft_term_init(void);
void		ft_prompt(void);
void		ft_aff_prompt(void);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Builtins
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

int			ft_detect_builtin(char *cmd);
void		ft_exec_builtin(t_btree *node);
void		ft_env(t_btree *node);
void		ft_unsetenv(t_btree *node);
void		ft_unsetenv_b(char *name, char ***env);
void		ft_setenv(t_btree *node);
void		ft_setenv_b(char *name, char *value, char ***env);
char		*ft_getvar_env(char *name, char **env);
void		ft_cd(t_btree *node);
void		ft_echo(t_btree *node);
void		ft_exit_builtin(t_btree *node);
int			ft_putput(int c);
void		ft_reset_term(void);
void		ft_raw_term(void);
void		ft_term_init(void);
void		ft_prompt(void);
void		ft_aff_prompt(void);
int			ft_has_char(char *str);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Parser / Lexer
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void		ft_lexer(char *str, t_dlist **list);
int			ft_lexer_check_err(t_dlist *list);
void		ft_parser(t_dlist **list, t_btree **tree);
void		add_node(t_btree **tree, void *data, size_t content_size);
int			ft_is_valid(char *line);

void		if_and(t_btree **tree, t_btree *node);
void		if_cmd(t_btree **tree, t_btree *node);
void		if_pipe(t_btree **tree, t_btree *node);
void		if_or(t_btree **tree, t_btree *node);
void		if_end(t_btree **tree, t_btree *node);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Exec
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

int			ft_launch(void);
void		ft_fork_and_exec(t_btree *node);
int			ft_exec(t_btree *node);
int			ft_fill_path(t_cmd *cmd);
t_cmd		*ft_make_cmd(char *path, char *e1, char *e2, char *e3, char **env);
int			ft_treat_node(t_btree *node);
int			ft_redirect(t_btree *node);

int			ft_create_files(t_btree *node);

int			treat_cmd(t_btree *node);
int			treat_pipe(t_btree *node);
int			treat_end(t_btree *node);
int			treat_and(t_btree *node);
int			treat_or(t_btree *node);
int			treat_chev(t_btree *node);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Error
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void		ft_error(char *msg);

void		print_tree(t_btree *node, int level, int dir); /* TODO delete */

#endif /* !A42SH_H */
