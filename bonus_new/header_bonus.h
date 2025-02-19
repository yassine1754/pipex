/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:52:07 by yadib             #+#    #+#             */
/*   Updated: 2025/02/19 16:21:09 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "parsing/parsing_bonus.h"

void	cmds_area(t_pairs *s_data, char *arg, int *pip);
void	change_in_out(int new_in, int new_out, t_pairs *s_data);
#endif