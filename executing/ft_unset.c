/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:09:22 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 03:26:51 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	message_print_unset(char *s, int exit_error)
{	
	t_cmds	*data;
	int		fd;
	char	*i;

	i = ft_itoa(exit_error);
	data = init_stuct();
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	ft_putstr_fd(i, fd);
	free(i);
}

int	error_unset(char *key)
{
	int	i;

	i = 0;
	if (key[i] != '_' && (ft_isalpha(key[i]) == 0))
	{
		message_print_unset(key, 1);
		return (1);
	}
	i++;
	while (key[i])
	{
		if (ft_isalpha(key[i]) == 1 || ft_isnum(key[i]) == 1 || key[i] == '_')
			i++;
		else
		{
			message_print_unset(keyex, 1);
		
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
