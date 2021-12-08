/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:31:51 by murachid          #+#    #+#             */
/*   Updated: 2021/12/08 15:40:41 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	mywrite(void)
{
	char	*buffer;
	int		res;
	int		fd;

	buffer = malloc(3);
	fd = open("/tmp/s_code", O_RDONLY, 0666);
	read(fd, buffer, 3);
	res = ft_atoi(buffer);
	free(buffer);
	return (res);
}

void	mywrite_int(void)
{
	int	fd;

	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	ft_putstr_fd("0", fd);
}

void	message_print_export(char *s, int exit_error)
{	
	t_cmds	*data;
	int		fd;
	char	*i;

	i = ft_itoa(exit_error);
	data = init_stuct();
	ft_itoa(exit_error);
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	ft_putstr_fd(i, fd);
}

void	message_print_red(char *s, char *str, int exit_error)
{	
	t_cmds	*data;
	int		fd;
	char	*i;

	i = ft_itoa(exit_error);
	data = init_stuct();
	print_error(s, str);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	ft_putstr_fd(i, fd);
}

void	message_print(char *s, char *str, int exit_error)
{	
	t_cmds	*data;
	int		fd;
	char	*i;

	i = ft_itoa(exit_error);
	data = init_stuct();
	print_error(s, str);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	ft_putstr_fd(i, fd);
	exit(0);
}
