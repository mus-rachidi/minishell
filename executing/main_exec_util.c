/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:41:40 by murachid          #+#    #+#             */
/*   Updated: 2021/12/07 19:42:36 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	mywait(void)
{
	while (1)
	{
		if (waitpid(-1, NULL, 0) <= 0)
			break ;
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

void	free_and_wait(t_node *head)
{
	mywait();
	check_t_child("0");
	printlist(head);
	freelist(head);
}
