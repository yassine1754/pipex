/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:59:15 by yadib             #+#    #+#             */
/*   Updated: 2025/02/18 11:36:58 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	prints_error(char error, char *to_print)
{
	if (error == PERMISION_DENIED)
		ft_putstr_fd("permission denied: ", 2);
	else if (error == FILE_NOT_FOUND)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (error == CMD_NOT_FOUND)
		ft_putstr_fd("command not found: ", 2);
	else if (error == ALLOCATION_FAIL)
		ft_putstr_fd("allocation Failed :", 2);
	else if (error == CANT_CREAED)
		ft_putstr_fd("can't create file : ", 2);
	else if (error == PIPE_FAIL)
		ft_putstr_fd("can't create a pipe .", 2);
	else if (error == FORK_FAIL)
		ft_putstr_fd("fork fail", 2);
	else if (error == DUPING_FAIL)
		ft_putstr_fd("DUPING is FAIL", 2);
	else if (error == EXCVE_ERNO)
		ft_putstr_fd("execve fail", 2);
	else if (error == NOT_ENOUGH)
		ft_putstr_fd(".: not enough arguments", 2);
	else if (error == IS_DIRECTORY)
		ft_putstr_fd("is a directory: ", 2);
	ft_putstr_fd(to_print, 2);
	ft_putchar_fd('\n', 2);
}

void	smart_exit(char error, char *to_print, t_pairs *s_data)
{
	if (error < 0)
	{
		if (s_data->pip[0] != -1)
			close(s_data->pip[0]);
		if (s_data->pip[1] != -1)
			close(s_data->pip[1]);
		prints_error(error, to_print);
	}
	free_strings(s_data->flags.cmd1);
	free_strings(s_data->flags.cmd2);
	free_strings(s_data->paths);
	free(s_data->path_cmd1);
	free(s_data->path_cmd2);
	if (error == NOT_A_PROBLEM)
		exit (0);
	exit (1);
}
