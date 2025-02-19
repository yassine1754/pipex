/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:51:57 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 16:29:35 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	change_in_out(int new_in, int new_out, t_pairs *s_data)
{
	if (dup2(new_in, 0) == -1)
	{
		close(new_in);
		close(new_out);
		smart_exit(DUPING_FAIL, NULL, s_data);
	}
	if (dup2(new_out, 1) == -1)
	{
		close(new_in);
		close(new_out);
		smart_exit(DUPING_FAIL, NULL, s_data);
	}
	close(new_in);
	close(new_out);
}

void	input_area_files(t_pairs *s_data, char *arg, int *pip)
{
	int	fd_in;

	check_file_input(s_data);
	s_data->flags.cmd1 = cmd_flags(s_data, arg);
	s_data->path_cmd1 = searsh_cmd_path
		(s_data->flags.cmd1[0], s_data->paths, s_data);
	close(pip[0]);
	pip[0] = -1;
	fd_in = open(s_data->input, O_RDONLY);
	change_in_out(fd_in, pip[1], s_data);
	if (execve
		(s_data->path_cmd1, s_data->flags.cmd1, s_data->paths) == -1)
		smart_exit(EXCVE_ERNO, NULL, s_data);
}

void	output_area_files(t_pairs *s_data, char *arg, int *pip)
{
	int	fd_out;

	check_file_output(s_data);
	s_data->flags.cmd2 = cmd_flags(s_data, arg);
	s_data->path_cmd2 = searsh_cmd_path
		(s_data->flags.cmd2[0], s_data->paths, s_data);
	fd_out = open(s_data->output, O_TRUNC | O_WRONLY);
	close(pip[1]);
	pip[1] = -1;
	change_in_out(pip[0], fd_out, s_data);
	if (execve(s_data->path_cmd2
			, s_data->flags.cmd2, s_data->paths) == -1)
		smart_exit(EXCVE_ERNO, NULL, s_data);
}

void	forking_bonus(t_pairs *s_data, char **arg, int *pip)
{
	int	pid;
	int	child;

	child = 2;
	while (child < s_data->ac - 1)
	{
		pid = fork();
		if (pid < 0)
			smart_exit(FORK_FAIL, NULL, s_data);
		else if (pid == 0 && child == 2)
			input_area_files(s_data, arg[child], pip);
		else if (pid == 0 && child == s_data->ac - 2)
			output_area_files(s_data, arg[child], pip);
		else if (pid == 0)
			cmds_area(s_data, arg[child], pip);
		child++;
	}
	s_data->help = 1;
	close(pip[0]);
	close(pip[1]);
	while (wait(&s_data->status) > 0)
		s_data->help_stat = WEXITSTATUS(s_data->status);
	if (s_data->help_stat)
		smart_exit(1, NULL, s_data);
	smart_exit(0, NULL, s_data);
}

int	main(int ac, char *argv[], char **env)
{
	t_pairs	s_data;

	if (ac < 5)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Enter ./pipex infile cmd1 cmd2 ... cmdn outfile\n", 2);
		exit(1);
	}
	s_data.ac = ac;
	subimt_data(&s_data, argv);
	find_paths_cmd(env, &s_data);
	if (pipe(s_data.pip) == -1)
		smart_exit(PIPE_FAIL, NULL, &s_data);
	forking_bonus(&s_data, argv, s_data.pip);
}
