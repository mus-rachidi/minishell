/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:46:48 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 01:20:39 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	print_error(char *a, char *b)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(a, 2);
	ft_putstr_fd(b, 2);
}

char	*ft_check_two(t_cmds *tmp1)
{
	int	fd;
	char *str_error;

	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);	
	str_error = NULL;
	if (tmp1->multiple == 1)
	{
		str_error = ft_strjoin(tmp1->check_error,
			" No such file or directory\n");
		ft_putstr_fd("1", fd);
	}
	if (tmp1->multiple == 2)
	{
		str_error = ft_strjoin(tmp1->check_error,
			" Permission denied\n");
		ft_putstr_fd("1", fd);
	}
	if (tmp1->multiple == 3)
	{
		str_error = ft_strjoin("", " ambiguous redirect\n");
		ft_putstr_fd("1", fd);
	}
	tmp1->check_error = NULL;
	return (str_error);
}

void	ft_check_exit(t_cmds *tmp1)
{
	if (tmp1->multiple == 1)
		exit(0);
	if (tmp1->multiple == 2)
		exit(0);
	if (tmp1->multiple == 3)
		exit(0);
}

char	*ft_check_error_two(t_cmds *cmds)
{
	DIR	*dir;

	dir = NULL;
	if (cmds->redrctions)
		dir = opendir(cmds->redrctions->name);
	if (access(cmds->redrctions->name, F_OK) == -1)
	{
		cmds->multiple = 1;
		return (cmds->redrctions->name);
	}
	if (access(cmds->redrctions->name, F_OK) == -1 && (cmds->redrctions && dir))
	{
		cmds->multiple = 1;
		return (cmds->redrctions->name);
	}
	else if (cmds->redrctions
		&& access(cmds->redrctions->name, W_OK | R_OK) == -1)
	{
		cmds->multiple = 2;
		return (cmds->redrctions->name);
	}
	return (NULL);
}

char	*ft_check_error_three(t_cmds *cmds)
{
	DIR	*dir;

	dir = NULL;
	if (cmds->redrctions)
		dir = opendir(cmds->redrctions->name);
	if (dir)
	{
		cmds->multiple = 1;
		return (cmds->redrctions->name);
	}
	if ((cmds->redrctions
			&& access(cmds->redrctions->name, W_OK | R_OK) == -1))
	{
		cmds->multiple = 2;
		return (cmds->redrctions->name);
	}
	return (NULL);
}
