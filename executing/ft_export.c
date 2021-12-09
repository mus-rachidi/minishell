/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:02:10 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 19:46:41 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

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

void	exe_export(t_cmds *tmp, struct s_data_item *temp)
{
	int			i;
	char		*key;
	char		*data;
	t_data_item	*d;

	i = 0;
	while (tmp->arguments[i])
	{
		key = key_export(tmp->arguments[i]);
		free_all(key);
		data = valeu_export(tmp->arguments[i]);
		if (error_export(key, tmp->arguments[i]) == 1)
		{
			i++;
			continue ;
		}
		d = search(key, temp);
		if (d && !data)
		{
			i++;
			if (key)
				free(key);
			continue ;
		}
		else
		{
			export_util(d, data, key);
			free(key);
		}
		i++;
	}
}
