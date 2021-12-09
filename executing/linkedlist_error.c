/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:13:01 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 21:57:45 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	printlist(t_node *head)
{
	t_node	*ptr;

	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data)
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
