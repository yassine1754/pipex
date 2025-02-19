/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:51:39 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 15:56:58 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "../utils/utils_bonus.h"

void	subimt_data(t_pairs *s_data, char **argv);
void	find_paths_cmd(char **env, t_pairs *s_data);
char	**cmd_flags(t_pairs *s_data, char *arg);
void	check_file_input(t_pairs *s_data);
void	check_file_output(t_pairs *s_data);
char	*searsh_cmd_path(char *cmd_name, char **paths,
			t_pairs *s_data);

#endif