/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:09:22 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 19:08:31 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	error_unset(char *key)
{
	int	i;

	i = 0;
	if (key[i] != '_' && (ft_isalpha(key[i]) == 0))
	{
		printf("minishell: unset: `%s': not a valid identifier\n", key);
		return (1);
	}
	i++;
	while (key[i])
	{
		if (ft_isalpha(key[i]) == 1 || ft_isnum(key[i]) == 1 || key[i] == '_')
			i++;
		else
		{
			printf("minishell: unset: `%s': not a valid identifier\n", key);
			return (1);
		}
	}
	return (0);
}

void	exe_unset(t_cmds *tmp, struct s_data_item *temp)
{
	int	i;

	i = 0;
	while (tmp->arguments[i])
	{
		temp = search(tmp->arguments[i], temp);
		if (temp != NULL)
			delete(temp);
		if (error_unset(tmp->arguments[i]) == 1)
		{
			i++;
			continue ;
		}
		i++;
	}
}
