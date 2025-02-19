# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadib <yadib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 17:50:18 by yadib             #+#    #+#              #
#    Updated: 2025/02/19 16:20:36 by yadib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex_bonus
CFLAGS = -Wall -Werror -Wextra

_UTILS_FILES = split_bonus.c strings_bonus.c smart_exit_bonus.c prints_bonus.c mini_tools_bonus.c

UTILS_FILES = $(addprefix utils/, $(_UTILS_FILES))
UTILS_OBJECT = $(UTILS_FILES:.c=.o)

_PARS_FILES = start_check_bonus.c submit_data_bonus.c

PARS_FILES = $(addprefix parsing/, $(_PARS_FILES))
PARS_OBJECT = $(PARS_FILES:.c=.o)

all: $(NAME)

bonus:
	make -C bonus_part 

$(NAME): $(UTILS_OBJECT) $(PARS_OBJECT) pipex_bonus.c header_bonus.h help_bonus.c
	cc $(CFLAGS) $(UTILS_OBJECT) $(PARS_OBJECT) pipex_bonus.c help_bonus.c -o $@

utils/%.o: utils/%.c utils/utils_bonus.h header_bonus.h
	cc $(CFLAGS) -c $< -o $@

parsing/%.o: parsing/%.c parsing/parsing_bonus.h header_bonus.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(UTILS_OBJECT) $(PARS_OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all