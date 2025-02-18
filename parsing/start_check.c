/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:51:28 by yadib             #+#    #+#             */
/*   Updated: 2025/02/18 11:10:57 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*check_cmd_path(char *cmd_path, t_pairs *s_data)
{
	int	fdir;

	fdir = open(cmd_path, O_DIRECTORY);
	close(fdir);
	if (access(cmd_path, F_OK) == -1)
		smart_exit(FILE_NOT_FOUND, cmd_path, s_data);
	else if (access(cmd_path, X_OK) == -1 || fdir != -1)
		smart_exit(PERMISION_DENIED, cmd_path, s_data);
	return (ft_strdup(cmd_path));
}

void	check_file_input(t_pairs *s_data)
{
	if (access(s_data->input, F_OK) == -1)
		return (
			smart_exit(FILE_NOT_FOUND, s_data->input, s_data));
	else if (access(s_data->input, R_OK) == -1
		|| !ft_strcmp("/dev/stdout", s_data->input))
		return (smart_exit(PERMISION_DENIED, s_data->input, s_data));
}

void	check_file_output(t_pairs *s_data)
{
	int	fd;
	int	fdir;

	fdir = open(s_data->output, O_DIRECTORY);
	close(fdir);
	if (fdir != -1)
		smart_exit(IS_DIRECTORY, s_data->output, s_data);
	if (access(s_data->output, F_OK) == -1)
	{
		fd = open(s_data->output, O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
			smart_exit(PERMISION_DENIED, s_data->output, s_data);
		close(fd);
	}
	else if (access(s_data->output, W_OK) == -1
		|| !ft_strcmp("/dev/stdin", s_data->output))
		smart_exit(PERMISION_DENIED, s_data->output, s_data);
}

char	*command_search_file(char *cmd, char **env,
			t_pairs *s_data)
{
	int		i;
	char	*cmd_file;

	i = 0;
	while (env[i])
	{
		cmd_file = ft_strjoin(env[i++], "/", 0);
		cmd_file = ft_strjoin(cmd_file, cmd, 1);
		if (cmd_file == NULL)
			return (smart_exit
				(ALLOCATION_FAIL, cmd, s_data), NULL);
		if (access(cmd_file, F_OK) != -1)
		{
			if (access(cmd_file, X_OK) != -1)
				return (cmd_file);
			smart_exit(PERMISION_DENIED, cmd, s_data);
		}
		free(cmd_file);
		cmd_file = NULL;
	}
	smart_exit(CMD_NOT_FOUND, cmd, s_data);
	return (NULL);
}

char	*searsh_cmd_path(char *cmd_name, char **paths,
			t_pairs *s_data)
{
	if (cmd_name && cmd_name[0] == '.' && cmd_name[1] == '\0')
		smart_exit(NOT_ENOUGH, NULL, s_data);
	if (ft_strrchr(cmd_name, '/') == 0)
	{
		if (paths == NULL)
			smart_exit(CMD_NOT_FOUND, cmd_name, s_data);
		return (command_search_file(cmd_name, paths, s_data));
	}
	else
		return (check_cmd_path(cmd_name, s_data));
}
