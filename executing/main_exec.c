/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:15:57 by murachid          #+#    #+#             */
/*   Updated: 2021/12/07 19:42:29 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	ft_child(t_cmds *tmp1, char **envs, t_fd *fd, int i)
{
	ft_check_exit(tmp1);
	if (tmp1->next_cmd)
		dup2(fd->fd_pipe[1], 1);
	if (fd->p)
		dup2(fd->p, 0);
	if (fd->fd_int != -1)
		dup2(fd->fd_int, 0);
	if (fd->fd_out != -1)
		dup2(fd->fd_out, 1);
	if (fd->fd_int != -1)
		close(fd->fd_int);
	if (fd->fd_out != -1)
		close(fd->fd_out);
	close(fd->fd_pipe[0]);
	exec_built_second(tmp1);
	if (i == 1 && tmp1->next_cmd)
		exec_built(tmp1);
	ft_executing_in_child(tmp1, envs);
}

void	ft_fork(t_cmds *tmp1, char **envs, t_fd *fd, int i)
{
	pid_t	pid;
	int		status;
	int		a;

	status = 0;
	pid = 0;
	fd->fd_int = -1;
	fd->fd_out = -1;
	ft_redirection(tmp1, fd);
	check_t_child("1");
	pid = fork();
	if (pid == -1)
		perror("minishell");
	else if (pid == 0)
		ft_child(tmp1, envs, fd, i);
	close(fd->fd_pipe[1]);
	if (i == 1 && !tmp1->next_cmd)
		exec_built(tmp1);
}

void	exec_cmd_test(t_cmds *cmds, char **envs)
{
	t_cmds		*tmp1;
	t_node		*head;
	t_fd		fd;
	char		*str_error;
	int			i;

	i = 0;
	head = NULL;
	fd.p = 0;
	tmp1 = cmds;
	while (tmp1)
	{
		if (pipe(fd.fd_pipe) == -1)
			exit(1);
		i++;
		ft_fork(tmp1, envs, &fd, i);
		str_error = ft_check_two(tmp1);
		head = insertfirst(str_error, head);
		free_arg(tmp1);
		if (fd.p)
			close(fd.p);
		fd.p = fd.fd_pipe[0];
		tmp1 = tmp1->next_cmd;
	}
	free_and_wait(head);
}
