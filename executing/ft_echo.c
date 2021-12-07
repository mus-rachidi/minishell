/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:07:53 by murachid          #+#    #+#             */
/*   Updated: 2021/12/05 11:40:26 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	egnore_option(char *arg)
{
	int	i;

	i = 0;
	if (arg && arg[i] == '-')
	{
		i++;
		if (arg[i] && arg[i] == 'n')
		{
			while (arg[i])
			{
				if (arg[i] != 'n')
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

void	exe_echo(t_cmds *tmp)
{
	int	i;

	i = 0;
	while (tmp->arguments[i] && egnore_option(tmp->arguments[i]))
		i++;
	while (tmp->arguments[i])
	{	
		printf("%s", tmp->arguments[i]);
		i++;
		if (tmp->arguments[i])
			printf(" ");
	}
	if (tmp->option == 0)
		printf("\n");
}
