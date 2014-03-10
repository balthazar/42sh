NAME				= yolosh

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I ./inc -I libft/inc
LIBS				= -L libft -lft -L /usr/lib -lncurses -ltermcap

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/context.c \
					  $(DIR_SRC)/error.c \
					  $(DIR_SRC)/signals.c \
					  $(DIR_SRC)/ft_clean.c \
					  $(DIR_SRC)/ft_loop.c \
					  $(DIR_SRC)/ft_lexer.c \
					  $(DIR_SRC)/ft_lexer_push.c \
					  $(DIR_SRC)/ft_init_cmd.c \
					  $(DIR_SRC)/ft_parser.c \
					  $(DIR_SRC)/ft_parser_tree.c \
					  $(DIR_SRC)/ft_parser_node.c \
					  $(DIR_SRC)/ft_parser_error.c \
					  $(DIR_SRC)/ft_treat_node.c \
					  $(DIR_SRC)/ft_fill_path.c \
					  $(DIR_SRC)/ft_exec.c \
					  $(DIR_SRC)/ft_fork_and_exec.c \
					  $(DIR_SRC)/ft_redirect.c \
					  $(DIR_SRC)/ft_get_env.c \
					  $(DIR_SRC)/ft_get_fd.c \
					  $(DIR_SRC)/ft_create_files.c \
					  $(DIR_SRC)/ft_close_files.c \
					  $(DIR_SRC)/treat_cmd.c \
					  $(DIR_SRC)/treat_pipe.c \
					  $(DIR_SRC)/treat_end.c \
					  $(DIR_SRC)/treat_and.c \
					  $(DIR_SRC)/treat_chev.c \
					  $(DIR_SRC)/treat_or.c \
					  $(DIR_SRC)/print_tree.c \
					  $(DIR_SRC)/ft_term_mode.c \
					  $(DIR_SRC)/ft_aff_prompt.c \
					  $(DIR_SRC)/ft_launch.c \
					  $(DIR_SRC)/ft_has_char.c \
					  $(DIR_SRC)/ft_is_valid.c \
					  $(DIR_SRC)/ft_builtin.c \
					  $(DIR_SRC)/ft_cd.c \
					  $(DIR_SRC)/ft_exit_builtin.c \
					  $(DIR_SRC)/ft_history.c \
					  $(DIR_SRC)/ft_history_utils.c \
					  $(DIR_SRC)/ft_history_delete.c \
					  $(DIR_SRC)/ft_history_write.c \
					  $(DIR_SRC)/ft_history_builtin.c \
					  $(DIR_SRC)/ft_exclamation.c \
					  $(DIR_SRC)/ft_env.c \
					  $(DIR_SRC)/ft_setenv.c \
					  $(DIR_SRC)/ft_unsetenv.c \
					  $(DIR_SRC)/ft_echo.c \
					  $(DIR_SRC)/ft_time_utils.c \
					  $(DIR_SRC)/ft_time_utils_two.c \
					  $(DIR_SRC)/ft_psone.c \
					  $(DIR_SRC)/ft_getvar_env.c \
					  $(DIR_SRC)/ft_odd_quotes.c \
					  $(DIR_SRC)/ft_add_char.c \
					  $(DIR_SRC)/ft_del_char.c \
					  $(DIR_SRC)/ft_treat_key.c \
					  $(DIR_SRC)/treat_key_enter.c \
					  $(DIR_SRC)/treat_key_left.c \
					  $(DIR_SRC)/treat_key_right.c \
					  $(DIR_SRC)/treat_key_ctrld.c \
					  $(DIR_SRC)/treat_key_delete.c \
					  $(DIR_SRC)/treat_key_backsp.c \
					  $(DIR_SRC)/treat_key_up.c \
					  $(DIR_SRC)/treat_key_down.c \
					  $(DIR_SRC)/treat_key_home.c \
					  $(DIR_SRC)/treat_key_end.c \
					  $(DIR_SRC)/ft_clean_line.c \
					  $(DIR_SRC)/ft_clear_line.c \
					  $(DIR_SRC)/ft_logpos.c \
					  $(DIR_SRC)/ft_move_cursor.c \
					  $(DIR_SRC)/ft_rewrite.c \
					  $(DIR_SRC)/ft_go_end.c \
					  $(DIR_SRC)/ft_exceed.c \
					  $(DIR_SRC)/ft_move_to.c \

# ---------------------------------------------------------------------------- #

DIR_LIST			= src
DIR_SRC				= src
DIR_INC				= inc
DIR_OBJ				= .obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ---------------------------------------------------------------------------- #

all: libft $(NAME)

libft:
	@$(MAKE) -C libft

$(addprefix $(DIR_OBJ)/, %.o): %.c $(DIR_INC)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAG) $(INCS) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
	for DIR in $(DIR_LIST); \
	do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
	done

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

.PHONY: clean fclean re debug libft
