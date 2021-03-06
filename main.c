/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:25:01 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/11 18:45:18 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_global.h"

int	check_t_child(char *flag_to_check)
{
	static int	global_check;

	if (flag_to_check)
	{
		if (*flag_to_check == '1')
			global_check = 1;
		if (*flag_to_check == '0')
			global_check = 0;
	}
	return (global_check);
}

void	ft_sgone(int numofsig)
{
	int	fd;

	if (numofsig == SIGINT)
	{
		fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
		write(2, "\n", 1);
		ft_putnbr_fd(130, fd);
		ft_putstr_fd("\0", fd);
		close (fd);
	}
	if (numofsig == SIGQUIT)
	{
		fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
		write(2, "Quit: 3\n", 9);
		ft_putnbr_fd(131, fd);
		ft_putstr_fd("\0", fd);
		close (fd);
	}
}

void	ft_tow(int numofsig)
{
	char		*buffer;
	int			fd;
	t_cmds		*fl;

	fl = init_stuct();
	fd = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0777);
	if (numofsig == SIGINT)
	{
		fl->s_code = 1;
		buffer = ft_strdup(rl_line_buffer);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		write(2, buffer, ft_strlen(buffer));
		write(2, "  \nUser@minishell> ", 20);
		free(buffer);
		close (fd);
	}
	if (numofsig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \b\b", 4);
	}
}

void	sig_handler(int numofsig)
{
	char	*ptr;
	t_cmds	*fl;

	fl = init_stuct();
	ptr = NULL;
	if (check_t_child(ptr) == 1)
		ft_sgone(numofsig);
	else
		ft_tow(numofsig);
}

int	main(int ac, char **av, char **envs)
{
	t_cmds		*fl;
	int			fd;
	int			fd1;

	ac = 0;
	av = NULL;
	fl = init_stuct();
	list_envs(envs);
	fd = open("/tmp/ls", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	fd1 = open("/tmp/s_code", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	close (fd);
	close (fd1);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		main_parsing(envs);
	}
	return (0);
}
