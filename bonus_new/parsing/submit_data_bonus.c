/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:59:04 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 16:04:30 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	subimt_data(t_pairs *s_data, char **argv)
{
	int ac;

	ac = s_data->ac;
	s_data->input = argv[1];
	s_data->output = argv[ac - 1];
	s_data->paths = NULL;
	s_data->flags.cmd1 = NULL;
	s_data->flags.cmd2 = NULL;
	s_data->flags.cur_cmd = NULL;
	s_data->curent_path = NULL;
	s_data->path_cmd1 = NULL;
	s_data->path_cmd2 = NULL;
	s_data->help = 0;
}

void	find_paths_cmd(char **env, t_pairs *s_data)
{
	char	*paths;

	paths = word_searsh_in_start("PATH=", env);
	s_data->paths = ft_split(paths, ':');
	if (paths && s_data->paths == NULL)
		smart_exit(ALLOCATION_FAIL, "paths", s_data);
}

char	**cmd_flags(t_pairs *s_data, char *arg)
{
	char	**flags;

	flags = NULL;
	if (arg == NULL || arg[0] == '\0')
		smart_exit(PERMISION_DENIED, "", s_data);
	flags = ft_split(arg, ' ');
	if (flags && flags[0] == NULL)
	{
		free(flags);
		return (smart_exit
			(CMD_NOT_FOUND, arg, s_data), NULL);
	}
	if (!flags)
	{
		return (smart_exit
			(ALLOCATION_FAIL, arg, s_data), NULL);
	}
	return (flags);
}
