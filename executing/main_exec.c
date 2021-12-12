/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:15:57 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 23:59:54 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

typedef struct s_exec_cmd
{
	int			i;
}t_exec_cmd;

typedef struct s_str
{
	t_cmds		*tmp1;
	t_node		*head;
	t_fd		fd;
	int			fd1;
	t_exec_cmd	ec;
	t_cmds		*fl;	
}t_str;

void	ft_child(t_cmds *tmp1, char **envs, t_fd *fd)
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
	ft_redirection(tmp1, fd, i);
	check_t_child("1");
	pid = fork();
	if (pid == -1)
		perror("minishell");
	else if (pid == 0)
		ft_child(tmp1, envs, fd);
	close(fd->fd_pipe[1]);
	exec_built(tmp1);
}

void	printn_file(void)
{
	char	*buffer;
	int		fd;
	int		fd1;
	int		r;

	buffer = malloc(3);
	fd = open("/tmp/ls", O_RDONLY, 0777);
	while (1)
	{
		r = read(fd, buffer, 1);
		if (r <= 0)
			break ;
		printf("%c", buffer[0]);
	}
	free(buffer);
	buffer = NULL;
	fd1 = open("/tmp/ls", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	close(fd);
	close(fd1);
}

void	tools_exec(t_str exe)
{
	t_cmds	*data;

	mywait();
	data = init_stuct();
	check_t_child("0");
	printlist(exe.head);
	data->s_code = mywrite();
	printn_file();
	freelist(exe.head);
}

void	exec_cmd_test(t_cmds *cmds, char **envs)
{
	t_str	exe;

	exe.fl = init_stuct();
	exe.ec.i = 0;
	exe.head = NULL;
	exe.fd.p = 0;
	exe.tmp1 = cmds;
	exe.fl->s_code = 0;
	while (exe.tmp1)
	{
		if (!exe.tmp1->next_cmd)
			exe.fl->g_check = 1;
		if (pipe(exe.fd.fd_pipe) == -1)
			exit(1);
		exe.ec.i++;
		ft_fork(exe.tmp1, envs, &exe.fd, exe.ec.i);
		exe.fl->str_error1 = ft_check_two(exe.tmp1);
		exe.head = insertfirst(exe.fl->str_error1, exe.head);
		free_arg(exe.tmp1);
		close_ft(exe.fd);
		exe.fd.p = exe.fd.fd_pipe[0];
		exe.tmp1 = exe.tmp1->next_cmd;
	}
	tools_exec(exe);
}
