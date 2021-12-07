/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:13:01 by murachid          #+#    #+#             */
/*   Updated: 2021/12/06 22:33:16 by rel-bour         ###   ########.fr       */
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
			printf("minishell : %s", ptr->data);
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
	return (head);
}
