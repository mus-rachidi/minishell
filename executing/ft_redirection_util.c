/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:06:32 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 18:19:31 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

char	*ft_ambiguous(t_cmds *cmds)
{
	if (cmds->redrctions->ambiguous == -1)
	{
		cmds->multiple = 3;
		return (cmds->redrctions->org_name);
	}
	return (NULL);
}

void	ft_overwrites(t_cmds *tmp1, t_fd *fd)
{
	if (!tmp1->check_error && access(tmp1->redrctions->name, F_OK) != -1)
		tmp1->check_error = ft_check_error_three(tmp1);
	if (tmp1->redrctions->ambiguous == -1)
		tmp1->check_error = ft_ambiguous(tmp1);
	if (!tmp1->check_error)
		fd->fd_out = open(tmp1->redrctions->name,
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

void	ft_append_intput(t_cmds *tmp1, t_fd *fd)
{
	fd->fd_int = open(tmp1->redrctions->name, O_RDONLY, 0777);
	if (!tmp1->check_error)
		tmp1->check_error = ft_check_error_two(tmp1);
}

void	ft_append_output(t_cmds *tmp1, t_fd *fd)
{
	if (!tmp1->check_error && access(tmp1->redrctions->name, F_OK) != -1)
		tmp1->check_error = ft_check_error_three(tmp1);
	if (!tmp1->check_error)
		fd->fd_out = open(tmp1->redrctions->name,
				O_WRONLY | O_CREAT | O_APPEND, 0777);
}

void	ft_here_doc(t_cmds *tmp1, t_fd *fd, int zero, int i)
{
	fd->fd_int = file_descriptor(tmp1, zero, i);
}
