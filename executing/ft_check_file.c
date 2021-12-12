/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:44:11 by murachid          #+#    #+#             */
/*   Updated: 2021/12/12 01:14:59 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

char	*ft_check_error_three(t_cmds *cmds)
{
	if ((cmds->redrctions
			&& access(cmds->redrctions->name, W_OK | R_OK) == -1))
	{
		cmds->multiple = 2;
		return (cmds->redrctions->name);
	}
	return (NULL);
}

void	close_two(int fd1, int fd2)
{
	close(fd2);
	close(fd1);
}
