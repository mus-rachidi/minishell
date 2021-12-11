/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:13:18 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 01:28:30 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	my_ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	check_exit_command(char *cmd)
{
	t_cmds		*fl;
	int			fd;
	char		*t;
	int			fd1;

	fl = init_stuct();
	fd = open("/tmp/ls", O_WRONLY | O_APPEND, 0666);
	fd1 = open("/tmp/s_code", O_WRONLY | O_TRUNC, 0666);
	write(fd, "minishell :", ft_strlen("minishel :"));
	t = ft_strjoin(cmd, ": command not found\n");
	write(fd, t, ft_strlen(t));
	if (fl->g_check == 1)
		ft_putstr_fd("127", fd1);
	else
		ft_putstr_fd("0", fd1);
}

void	ft_join(t_pipex *pipex, char *cmd)
{
	int			i;

	i = 0;
	pipex->path_split = ft_split(pipex->path, ':');
	while (pipex->path_split[i])
	{
		pipex->bin = ft_strdup(pipex->path_split[i]);
		pipex->temp = pipex->bin;
		pipex->bin = ft_strjoin(pipex->bin, "/");
		free(pipex->temp);
		pipex->temp = pipex->bin;
		pipex->bin = ft_strjoin(pipex->bin, cmd);
		free(pipex->temp);
		pipex->fd = open(pipex->bin, O_RDONLY);
		if (pipex->fd != -1)
			break ;
		else
			free(pipex->bin);
		i++;
	}
	if (pipex->fd == -1)
		check_exit_command(cmd);
}
