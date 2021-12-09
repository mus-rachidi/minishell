/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:26:17 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:48:06 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	export_util(t_data_item *d, char *data, char *key)
{
	if (d)
	{
		delete(d);
		insert(key, data);
	}
	else
		insert(key, data);
}

char	*valeu_export(char *tmp)
{
	char	*t;

	t = tmp;
	if (my_ft_strchr(t) == 1)
	{
		t = ft_strchr(t, '=');
		return (t + 1);
	}
	else
		return (NULL);
	t = tmp;
	return (t);
}

int	error_export(char *key, char *arg)
{
	int	i;

	i = 0;
	if (!key)
	{
		message_print_export(arg, 1);
		return (1);
	}
	if (key[i] != '_' && (ft_isalpha(key[i]) == 0))
	{
		message_print_export(arg, 1);
		return (1);
	}
	i++;
	while (key[i])
	{
		if (ft_isalpha(key[i]) == 1 || ft_isnum(key[i]) == 1 || key[i] == '_' )
			i++;
		else
		{
			message_print_export(arg, 1);
			return (1);
		}
	}
	return (0);
}

char	*key_export(char *tmp)
{
	char	**t;
	char	*tmp1;

	if (tmp)
	{
		t = ft_split(tmp, '=');
		tmp1 = ft_strdup(t[0]);
		free_array(t);
		return (tmp1);
	}	
	else
		return (NULL);
}
