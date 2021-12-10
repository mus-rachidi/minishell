/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:51:22 by murachid          #+#    #+#             */
/*   Updated: 2021/12/10 20:23:13 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing_head.h"

void	print_disply(t_cmds *tmp, struct s_data_item *temp, int *i)
{
	if (!ft_strcmp("export", tmp->type) && !tmp->arguments[0])
	{
		if (!temp->data)
			printf("declare -x %s\n", temp->key);
		else
			printf("declare -x %s=\"%s\"\n", temp->key, temp->data);
	}
	else
	{	
		if (!temp->data)
			i++;
		else
			printf("%s=%s\n", temp->key, temp->data);
	}
}

int	hashcode(char *chaine)
{
	int	i;
	int	numberhash;

	numberhash = 0;
	i = 0;
	while (chaine[i] != '\0')
	{
		numberhash += chaine[i];
		i++;
	}
	numberhash %= SIZE;
	return (numberhash);
}

int	delete_element(struct s_data_item **t, char *key)
{
	struct s_data_item	*temp;
	struct s_data_item	*prev;

	temp = *t;
	if (temp != NULL && temp->key == key)
	{
		*t = temp->next;
		return (1);
	}
	while (temp != NULL && temp->key != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return (1);
	prev->next = temp->next;
	return (0);
}
