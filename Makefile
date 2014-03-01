#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2014/01/23 23:45:20 by mpillet           #+#    #+#             *#
#*   Updated: 2014/03/01 00:34:05 by mpillet          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# ============================================================================ #
# oo                               42sh                                     oo #
# ============================================================================ #

NAME				= 42sh

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I ./inc -I libft/inc
LIBS				= -L libft -lft

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/context.c \
					  $(DIR_SRC)/error.c \
					  $(DIR_SRC)/ft_lexer.c \
					  $(DIR_SRC)/ft_parser.c \
					  $(DIR_SRC)/ft_parser_tree.c \
					  $(DIR_SRC)/ft_parser_node.c \
					  $(DIR_SRC)/ft_parser_error.c \
					  $(DIR_SRC)/ft_treat_node.c \
					  $(DIR_SRC)/ft_make_cmd.c \
					  $(DIR_SRC)/ft_fill_path.c \
					  $(DIR_SRC)/ft_exec.c \
					  $(DIR_SRC)/ft_fork_and_exec.c \
					  $(DIR_SRC)/ft_redirect.c \
					  $(DIR_SRC)/ft_get_env.c \
					  $(DIR_SRC)/ft_create_files.c \
					  $(DIR_SRC)/ft_test.c \
					  $(DIR_SRC)/treat_cmd.c \
					  $(DIR_SRC)/treat_pipe.c \
					  $(DIR_SRC)/treat_end.c \
					  $(DIR_SRC)/treat_and.c \
					  $(DIR_SRC)/treat_chev.c \
					  $(DIR_SRC)/treat_or.c \
					  $(DIR_SRC)/print_tree.c \

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
