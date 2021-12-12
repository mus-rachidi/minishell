/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:46:48 by murachid          #+#    #+#             */
/*   Updated: 2021/12/12 01:08:24 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	print_error(char *a, char *b)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(a, 2);
	ft_putstr_fd(b, 2);
}

char	*print_e(int fd, int c, char *s, char *s1)
{
	char	*str_error2;

	str_error2 = ft_strjoin(s, s1);
	if (!c)
		ft_putnbr_fd(1, fd);
	ft_putstr_fd("\0", fd);
	return (str_error2);
}

char	*ft_check_two(t_cmds *tmp1)
{
	int		fd;
	char	*str_error2;
	int		c;

	c = 0;
	fd = -1;
	if (!check_file_size())
	{
		c = 1;
		fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	}
	str_error2 = NULL;
	if (tmp1->multiple == 1)
		str_error2 = print_e(fd, c, tmp1->check_error,
				" No such file or directory\n");
	if (tmp1->multiple == 2)
		str_error2 = print_e(fd, c, tmp1->check_error, " Permission denied\n");
	if (tmp1->multiple == 3)
		str_error2 = print_e(fd, c, "", " ambiguous redirect\n");
	tmp1->check_error = NULL;
	close(fd);
	return (str_error2);
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
	if (access(cmds->redrctions->name, F_OK) == -1)
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
