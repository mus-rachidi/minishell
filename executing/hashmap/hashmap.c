/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:51:41 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 00:14:40 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing_head.h"

void	delete(struct s_data_item *temp)
{
	char	*key;
	int		hashindex;
	int		l;

	key = temp->key;
	hashindex = hashcode(key);
	l = 0;
	while (l < SIZE)
	{
		temp = g_hasharray[l];
		while (temp)
		{
			if (delete_element(&temp, key) == 1)
				break ;
		}
		l++;
	}
}

void	display(t_cmds *tmp, struct s_data_item *temp)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		temp = g_hasharray[i];
		while (temp)
		{
			if (temp != NULL)
				print_disply(tmp, temp, &i);
			temp = temp->next;
		}
		i++;
	}
}

void	freelist1(t_data_item *head)
{
	t_data_item	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	insert(char *key, char *data)
{
	t_data_item		*temp;
	t_data_item		*item;
	int				hashindex;

	item = (t_data_item *)malloc(sizeof(t_data_item));
	item->data = ft_strdup(data);
	item->key = ft_strdup(key);
	item->next = NULL;
	hashindex = hashcode(key);
	if (g_hasharray[hashindex] == NULL)
		g_hasharray[hashindex] = item;
	else
	{
		temp = g_hasharray[hashindex];
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = item;
	}
}

struct	s_data_item	*search(char *key, struct s_data_item *temp)
{
	int	l;

	l = 0;
	while (l < SIZE)
	{
		temp = g_hasharray[l];
		while (temp)
		{	
			if (ft_strcmp(temp->key, key) == 0)
				return (temp);
			temp = temp->next;
		}
		l++;
	}
	return (NULL);
}
