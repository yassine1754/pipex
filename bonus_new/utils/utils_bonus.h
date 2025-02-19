/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:55:50 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 16:04:08 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_names
{
	NOT_A_PROBLEM = 0,
	FILE_NOT_FOUND = -1,
	PERMISION_DENIED = -2,
	CMD_NOT_FOUND = -3,
	ALLOCATION_FAIL = -4,
	CANT_CREAED = -5,
	PIPE_FAIL = -6,
	FORK_FAIL = -7,
	DUPING_FAIL = -8,
	EXCVE_ERNO = -9,
	NOT_ENOUGH = -10,
	IS_DIRECTORY = -11,
}	t_names;

typedef struct s_flgs
{
	char	**cmd1;
	char	**cmd2;
	char	**cur_cmd;
}	t_flag;

typedef struct s_pairs
{
	int		ac;
	int		help;
	int		status;
	int		help_stat;
	char	*input;
	char	*output;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*curent_path;
	char	**paths;
	int		pip[2];
	t_flag	flags;
}	t_pairs;

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *org_str, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	smart_exit(char error, char *to_print, t_pairs *s_data);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*word_searsh_in_start(char *word, char **to_searsh);
char	**free_strings(char **strings);
char	*ft_strjoin(char const *s1, char const *s2, char macro);
void	prints_error(char error, char *to_print);
char	ft_strcmp(const char *s1, const char *s2);
void	sleep_for_while(void);
#endif