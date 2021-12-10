/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util_exe_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:18:47 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 00:23:08 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	close_ft(t_fd fd)
{
	if (fd.p)
		close(fd.p);
}

void	ft_util(void)
{
	t_cmds	*data;

	data = init_stuct();
	free_and_wait();
	data->s_code = mywrite();
}
