# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadib <yadib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 17:50:18 by yadib             #+#    #+#              #
#    Updated: 2025/02/18 11:31:11 by yadib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Werror -Wextra

_UTILS_FILES = split.c strings.c smart_exit.c prints.c mini_tools.c

UTILS_FILES = $(addprefix utils/, $(_UTILS_FILES))
UTILS_OBJECT = $(UTILS_FILES:.c=.o)

_PARS_FILES = start_check.c submit_data.c

PARS_FILES = $(addprefix parsing/, $(_PARS_FILES))
PARS_OBJECT = $(PARS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(UTILS_OBJECT) $(PARS_OBJECT) pipex.c header.h
	cc $(CFLAGS) $(UTILS_OBJECT) $(PARS_OBJECT) pipex.c -o $@

utils/%.o: utils/%.c utils/utils.h header.h
	cc $(CFLAGS) -c $< -o $@

parsing/%.o: parsing/%.c parsing/parsing.h header.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(UTILS_OBJECT) $(PARS_OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all