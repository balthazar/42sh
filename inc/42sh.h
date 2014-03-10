#ifndef A42SH_H
# define A42SH_H

# include <stdio.h> /* TODO delete */

# include <termios.h>
# include <curses.h>
# include <term.h>
# include <time.h>
# include "libft.h"

# define BUF_LEN		6
# define LINE_LEN		2048

# define CTX			ft_get_ctx()
# define ENV			CTX->env

# define CMD			0
# define CHEV			1
# define PIPE			2
# define END			3
# define AND			4
# define OR				5
# define QUOTE			6
# define STR			-1

# define TRUE			1
# define FALSE			0

# define OP_S			1
# define OP_D			2

# define FIRST			1
# define SECOND			2
# define LOSER			3
# define JOB(X)			((t_jobs *)X->content)

# define LIST			((t_elem *)list->content)
# define PREV			((t_elem *)list->prev->content)
# define NEXT			((t_elem *)list->next->content)

# define D_NODE			((t_cmd *)first->content)->type
# define D_TREE			((t_cmd *)node->content)->type
# define RIGHT			((t_cmd *)first->right->content)
# define LEFT			((t_cmd *)first->left->content)

# define C(EL)			((t_cmd *) EL->content)
# define CH(X)			(((t_chev *)X->content))

# define NB_KEYS		8
# define K_LEFT			tgetstr("kl", NULL)
# define K_RIGHT		tgetstr("kr", NULL)
# define K_DOWN			tgetstr("kd", NULL)
# define K_UP			tgetstr("ku", NULL)
# define K_DELETE		tgetstr("kD", NULL)
# define K_ENTER		tgetstr("cr", NULL)
# define K_BACKSP		("\177")
# define K_CTRLD		("\004")

# define GETT(E, T)		((t_cmd *) (E)->content)->T
# define CMU			(GETT(node, cmd)[1])
# define CNIL			(!ft_strcmp(GETT(node, cmd)[1], "-i"))
# define PS				ctx->psone
# define HIS			ctx->history
# define NBTIME			7
# define NBBS			8
# define UP				1
# define DOWN			2

typedef struct		s_stime
{
	char			*type;
	char			*(*fn)(struct tm *local);
}					t_stime;

typedef struct		s_psone
{
	char			*str;
	int				realsize;
}					t_psone;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_ctx
{
	char			**env;
	char			line[LINE_LEN];
	char			buf[BUF_LEN];
	int				cols;
	int				rows;
	int				prompt;
	int				i;
	int				len;
	t_psone			*psone;
	t_dlist			*history;
	t_dlist			*cur_h;
	t_dlist			*end_h;
	int				cpt_h;
	char			save[LINE_LEN];
	t_list			*jobs;
	t_pos			pos;
	int				sub_proc;
	int				prompt_len;
	int				sub_shell;
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
	char			**custom;
	t_list			*in;
	t_list			*out;
	int				fd_in;
	int				fd_out;
	int				fail;
	int				force_null;
}					t_cmd;

typedef struct		s_key
{
	char			*key;
	int				(*fn)(void);
}					t_key;

typedef struct		s_built
{
	char			*name;
	void			(*fn)();
}					t_built;

typedef struct		s_jobs
{
	pid_t			pid;
	char			*line;
	int				first;
	int				nb;
}					t_jobs;

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Commons
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

int					ft_get_fd(void);
char				**ft_get_env(void);
t_ctx				*ft_get_ctx(void);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Termcaps
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_add_char(char c);
void				ft_insert_char(char c);
void				ft_del_char(void);
int					ft_putput(int c);
void				ft_reset_term(void);
void				ft_raw_term(void);
void				ft_term_init(void);
void				ft_prompt(void);
void				ft_aff_prompt(void);
int					ft_odd_quotes(char *line);
int					ft_treat_key(char *buf);
int					ft_has_char(char *str);
int					ft_loop(void);
void				ft_clean_line(void);
void				ft_clear_line(void);
void				ft_move_cursor(void);
void				ft_rewrite(int hard);
void				ft_go_end(int cols);
void				ft_move_to(int pos);

int					treat_key_enter(void);
int					treat_key_left(void);
int					treat_key_right(void);
int					treat_key_ctrld(void);
int					treat_key_delete(void);
int					treat_key_backsp(void);
int					treat_key_up(void);
int					treat_key_down(void);

int					ft_putput(int c);
void				ft_reset_term(void);
void				ft_raw_term(void);
void				ft_term_init(void);
void				ft_prompt(void);
void				ft_aff_prompt(void);
int					ft_has_char(char *str);

int					ft_exceed(void);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Builtins
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

int					ft_detect_builtin(char *cmd);
void				ft_exec_builtin(t_btree *node);
void				ft_env(t_btree *node);
void				ft_unsetenv(t_btree *node);
void				ft_unsetenv_b(char *name, char ***env);
void				ft_setenv(t_btree *node);
void				ft_setenv_b(char *name, char *value, char ***env);
char				*ft_getvar_env(char *name, char **env);
void				ft_cd(t_btree *node);
void				ft_echo(t_btree *node);
void				ft_exit_builtin(t_btree *node);
void				ft_rmline_tab(char *name, char ***arr, int len);
void				ft_history_builtin(t_btree *node);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Parser / Lexer
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_lexer(char *str, t_dlist **list);
int					ft_lexer_check_err(t_dlist *list);
void				ft_parser(t_dlist **list, t_btree **tree);
void				add_node(t_btree **tree, void *data, size_t content_size);
int					ft_is_valid(char *line);
void				if_and(t_btree **tree, t_btree *node);
void				if_cmd(t_btree **tree, t_btree *node);
void				if_pipe(t_btree **tree, t_btree *node);
void				if_or(t_btree **tree, t_btree *node);
void				if_end(t_btree **tree, t_btree *node);

int					ft_push_char(char *line, int i, t_dlist **list);
int					ft_push_sep(char *line, int i, t_dlist **list);
int					ft_push_quote(char *line, int i, t_dlist **list);
int					is_sep(char c);
void				ft_init_cmd(t_cmd *cmd);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Exec
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_clean(t_btree **tree, t_dlist **dlist);
int					ft_launch(t_btree *tree, t_dlist *dlist);
void				ft_fork_and_exec(t_btree *node);
int					ft_exec(t_btree *node);
int					ft_fill_path(t_cmd *cmd);
int					ft_treat_node(t_btree *node);
int					ft_redirect(t_btree *node);
int					ft_create_files(t_btree *node);
int					treat_cmd(t_btree *node);
int					treat_pipe(t_btree *node);
int					treat_end(t_btree *node);
int					treat_and(t_btree *node);
int					treat_or(t_btree *node);
int					treat_chev(t_btree *node);
int					ft_close_files(t_btree *node);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** PS1 & time
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_psone(char **env, t_ctx *ctx);
void				ft_timepurpose(t_ctx *ctx);
char				*ft_time_majd(struct tm *l);
char				*ft_time_majw(struct tm *l);
char				*ft_time_majt(struct tm *l);
char				*ft_time_w(struct tm *l);
char				*ft_time_star(struct tm *l);
char				*ft_time_twelve(struct tm *l);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** History & Exclamation
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/
void				ft_load_history(t_ctx *ctx, int fd, char *tmp, t_dlist *n);
int					ft_count_history(void);
void				ft_print_history(void);
void				ft_print_hist_from(int number);
void				ft_add_history(char *str);
void				ft_reset_line(t_ctx *ctx, int flag);
void				ft_delete_history(t_ctx *ctx);
void				ft_delete_specific_history(t_ctx *ctx, int nb, int cpt);
void				ft_append_new_history(char *filename, t_ctx *ctx);
void				ft_write_history(char *filename, t_ctx *ctx);
void				ft_get_newlines(char *filename, t_ctx *ctx, int fdsave);
void				ft_save_newlines(char *filename, t_ctx *ctx);

char				*ft_return_specific(char *str);
int					ft_isexcl(int c);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Error
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				ft_error(char *msg);
int					ft_err(char *msg);
void				ft_exit(int n);

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Signals
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void				setup_signal(void);
void				reset_signal(void);
void				ft_fg(int i);
void				ft_ctrlz(int sig);
void					ft_lst_del_job(t_list **list, t_list *node);

void		print_tree(t_btree *node, int level, int dir); /* TODO delete */
void		ft_logpos(void);

#endif /* !A42SH_H */
