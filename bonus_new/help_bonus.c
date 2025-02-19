/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:12:29 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 16:12:46 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	cmds_area(t_pairs *s_data, char *arg, int *pip)
{
	s_data->flags.cur_cmd = cmd_flags(s_data, arg);
	s_data->curent_path = searsh_cmd_path
		(s_data->flags.cur_cmd[0], s_data->paths, s_data);
	change_in_out(pip[0], pip[1], s_data);
	if (execve(s_data->curent_path
			, s_data->flags.cur_cmd, s_data->paths) == -1)
		smart_exit(EXCVE_ERNO, NULL, s_data);
}
