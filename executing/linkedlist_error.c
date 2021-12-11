/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:13:01 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 14:39:16 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	printlist(t_node *head)
{
	t_node	*ptr;

	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data && !check_file_size())
			message_print_red("", ptr->data, 1);
		ptr = ptr->next;
	}
}

t_node	*insertfirst(char *data, t_node *head)
{
	t_node	*link;

	link = (t_node *) malloc(sizeof(t_node));
	link->data = data;
	link->next = head;
	head = link;
	free_one(data);
	return (head);
}
