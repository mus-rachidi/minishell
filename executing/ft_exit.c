/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:31:51 by murachid          #+#    #+#             */
/*   Updated: 2021/12/10 23:10:44 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	mywrite(void)
{
	char	*buffer;
	int		res;
	int		fd;

	buffer = malloc(4);
	fd = open("/tmp/s_code", O_RDONLY, 0666);
	read(fd, buffer, 3);
	res = ft_atoi(buffer);
	open("/tmp/s_code", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(buffer);
	return (res);
}

void	message_print_export(char *s, int exit_error)
{	
	t_cmds	*data;
	int		fd;
	char	*i;

	i = ft_itoa(exit_error);
	data = init_stuct();
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	ft_putstr_fd(i, fd);
	free(i);
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
	free(i);
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
