/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:15:57 by murachid          #+#    #+#             */
/*   Updated: 2021/12/10 19:37:03 by murachid         ###   ########.fr       */
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
	if (i > 1 && !tmp1->next_cmd)
		exec_built(tmp1);
	ft_executing_in_child(tmp1, envs);
}

void	ft_fork(t_cmds *tmp1, char **envs, t_fd *fd, int i)
{
	pid_t	pid;
	int		status;

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
	if (i == 1 || (i == 1 && !ft_strcmp(tmp1->type, "exit")))
		exec_built(tmp1);
}

void	ft_util(t_node	*head)
{
	t_cmds	*data;

	data = init_stuct();
	free_and_wait(head);
	data->s_code = mywrite();
	mywrite_int();
}

void	close_ft(t_fd fd)
{
	if (fd.p)
		close(fd.p);
}

typedef struct s_exec_cmd
{
	char		*str_error;
	int			i;
}t_exec_cmd;

typedef struct s_str
{
	t_cmds		*tmp1;
	t_node		*head;
	t_fd		fd;
	t_exec_cmd	ec;
	t_cmds		*fl;	
}t_str;

void	exec_cmd_test(t_cmds *cmds, char **envs)
{
	t_str	exe;

	exe.fl = init_stuct();
	exe.ec.i = 0;
	exe.head = NULL;
	exe.fd.p = 0;
	exe.tmp1 = cmds;
	while (exe.tmp1)
	{
		if (!exe.tmp1->next_cmd)
			exe.fl->g_check = 0;
		if (pipe(exe.fd.fd_pipe) == -1)
			exit(1);
		exe.ec.i++;
		ft_fork(exe.tmp1, envs, &exe.fd, exe.ec.i);
		exe.ec.str_error = ft_check_two(exe.tmp1);
		exe.head = insertfirst(exe.ec.str_error, exe.head);
		free_arg(exe.tmp1);
		close_ft(exe.fd);
		exe.fd.p = exe.fd.fd_pipe[0];
		exe.tmp1 = exe.tmp1->next_cmd;
	}
	ft_util(exe.head);
}
