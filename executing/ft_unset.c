/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:09:22 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 18:52:58 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	message_print_unset(char *s, int exit_error)
{	
	int		fd;
	int		fd1;
	char	*t;

	fd1 = open("/tmp/ls", O_WRONLY | O_APPEND, 0777);
	write(fd1, "minishell :", ft_strlen("minishel :"));
	t = ft_strjoin(s, "': not a valid identifier\n");
	write(fd1, t, ft_strlen(t));
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	ft_putnbr_fd(exit_error, fd);
	ft_putstr_fd("\0", fd);
	close (fd);
	close(fd1);
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
			message_print_unset(key, 1);
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
