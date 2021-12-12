/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:41:40 by murachid          #+#    #+#             */
/*   Updated: 2021/12/12 00:18:12 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	mywait(void)
{
	t_cmds	*fl;
	int		a;
	int		fd;
	int		status;

	fl = init_stuct();
	while (1)
	{
		if (waitpid(-1, &status, 0) <= 0)
			break ;
	}
	if (WIFEXITED(status))
	{	
		a = WEXITSTATUS(status);
		if (a == 1)
		{
			fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
			ft_putnbr_fd(a, fd);
			close(fd);
		}
	}
}

void	freelist(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_arg(t_cmds *tmp1)
{
	int	j;

	j = 0;
	while (tmp1->arguments && tmp1->arguments[j])
	{
		free(tmp1->arguments[j]);
		tmp1->arguments[j] = NULL;
		j++;
	}
}
