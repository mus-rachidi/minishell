/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:31:51 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 18:51:58 by murachid         ###   ########.fr       */
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
}t_writ;

int	mywrite(void)
{
	t_writ		a;

	a.s = ft_strdup("");
	a.buffer = malloc(2);
	a.fd = open("/tmp/s_code", O_RDONLY);
	while (1)
	{
		a.r = read(a.fd, a.buffer, 1);
		a.buffer[1] = '\0';
		if (a.r <= 0)
			break ;
		a.s = ft_strjoin(a.s, a.buffer);
	}
	a.res = ft_atoi(a.s);
	a.fd1 = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	free(a.buffer);
	a.buffer = NULL;
	close(a.fd);
	close(a.fd1);
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

	check = malloc(3);
	fd = open("/tmp/s_code", O_RDONLY);
	if (read(fd, check, 3) == 0)
	{
		close (fd);
		return (0);
	}	
	else
	{
		close (fd);
		return (1);
	}
	free(check);
	check = NULL;
}
