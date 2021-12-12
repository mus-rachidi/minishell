/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:31:51 by murachid          #+#    #+#             */
/*   Updated: 2021/12/12 00:21:03 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

typedef struct s_writ
{
	char	*buffer;
	int		res;
	int		fd;
	int		fd1;
	int		r;
	char	*s;
	char	*tmp_f;
}t_writ;

int	mywrite(void)
{
	t_writ		a;

	a.s = ft_strdup("\0");
	a.buffer = malloc(2);
	a.fd = open("/tmp/s_code", O_RDONLY);
	while (1)
	{
		a.r = read(a.fd, a.buffer, 1);
		a.buffer[1] = '\0';
		if (a.r <= 0)
		{
			free_one(a.s);
			break ;
		}
		a.tmp_f = a.s;
		a.s = ft_strjoin(a.s, a.buffer);
		free_one(a.tmp_f);
		a.tmp_f = NULL;
	}
	a.res = ft_atoi(a.s);
	a.fd1 = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	free(a.buffer);
	a.buffer = NULL;
	close_two(a.fd, a.fd1);
	return (a.res);
}

void	message_print_export(char *s, int exit_error)
{
	int		fd;

	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	ft_putnbr_fd(exit_error, fd);
	ft_putstr_fd("\0", fd);
	close(fd);
}

void	message_print_red(char *s, char *str, int exit_error)
{
	int		fd;

	print_error(s, str);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	ft_putnbr_fd(exit_error, fd);
	ft_putstr_fd("\0", fd);
	close(fd);
}

void	message_print(char *s, char *str, int exit_error)
{	
	int		fd;

	print_error(s, str);
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	ft_putnbr_fd(exit_error, fd);
	ft_putstr_fd("\0", fd);
	close(fd);
	exit(0);
}

int	check_file_size(void)
{
	char	*check;
	int		fd;
	int		ret;

	check = malloc(3);
	fd = open("/tmp/s_code", O_RDONLY);
	if (read(fd, check, 3) == 0)
		ret = 0;
	else
		ret = 1;
	free_one(check);
	close (fd);
	return (ret);
}
