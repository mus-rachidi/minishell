/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:15:57 by murachid          #+#    #+#             */
/*   Updated: 2021/12/07 00:12:51 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"
// int     save_and_restore_fd(int action)
// {
//     static int  fds[3] = {-1};

//     if (action == 0)              
//     {
//         fds[STDIN_FILENO] = dup(STDIN_FILENO);
//         fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
//         fds[STDERR_FILENO] = dup(STDERR_FILENO);
//     }
//     else if (action == 1)
//     {
//         dup2(fds[STDIN_FILENO], STDIN_FILENO);
//         close(fds[STDIN_FILENO]);
//         dup2(fds[STDOUT_FILENO], STDOUT_FILENO);
//         close(fds[STDOUT_FILENO]);
//         dup2(fds[STDERR_FILENO], STDERR_FILENO);
//         close(fds[STDERR_FILENO]);
//     }
//     return (1);
// }
void	ft_child(t_cmds *tmp1, char **envs, t_fd *fd, int i)
{
	ft_check_exit(tmp1);
	if (tmp1->next_cmd)
	{
		dup2(fd->fd_pipe[1], 1);
		close(fd->fd_pipe[1]);
	}
	if (fd->p)
	{
		dup2(fd->p, 0);
		close(fd->p);
	}
	if (fd->fd_int != -1)
		dup2(fd->fd_int, 0);
	if (fd->fd_out != -1)
		dup2(fd->fd_out, 1);
	if (fd->fd_int != -1)
		close(fd->fd_int);
	if (fd->fd_out != -1)
		close(fd->fd_out);
	if(!tmp1->next_cmd)
	{
		close(fd->fd_pipe[0]);
		close(fd->fd_pipe[1]);
	}
	close(fd->fd_pipe[0]);
	exec_built_second(tmp1);
	if (i == 1 && tmp1->next_cmd)
		exec_built(tmp1);
	ft_executing_in_child(tmp1, envs);
}

void	mywait(void)
{
	while (1)
	{
		if (waitpid(-1, NULL, 0) <= 0)
			break ;
	}
}

void	ft_fork(t_cmds *tmp1, char **envs, t_fd *fd, int i)
{
	pid_t	pid;
	int		status;
	int		a;

	status = 0;
	pid = 0;
	check_t_child("1");
	pid = fork();
	if (pid == -1)
		perror("minishell");
	else if (pid == 0)
		ft_child(tmp1, envs, fd, i);
	close(fd->fd_pipe[1]);
	check_t_child("0");
}

void freelist(t_node* head)
{
   t_node *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

void	exec_cmd_test(t_cmds *cmds, char **envs)
{
	t_cmds		*tmp1;
	t_fd		fd;
	char		*str_error;
	t_node		*head;
	int			i;
	fd.p = 0;
	i = 0;
	head = NULL;
	str_error = NULL;
	tmp1 = cmds;
	int j;
	while (tmp1)
	{
		if (pipe(fd.fd_pipe) == -1)
			exit(1);
		i++;
		fd.fd_int = -1;
		fd.fd_out = -1;
		ft_redirection(tmp1, &fd);
		ft_fork(tmp1, envs, &fd, i);
		if (i == 1 && !tmp1->next_cmd)
			exec_built(tmp1);
		str_error = ft_check_two(tmp1);
		head = insertfirst(str_error, head);
		
		j = 0;
		while (tmp1->arguments && tmp1->arguments[j])
		{
			free(tmp1->arguments[j]);
			tmp1->arguments[j] = NULL;
			j++;
		}
		if(fd.p)
			close(fd.p);
		fd.p = fd.fd_pipe[0];
		tmp1 = tmp1->next_cmd;
	}
	while (1)
	{
		if (waitpid(-1, NULL, 0) <= 0)
			break ;
	}
	printlist(head);
	freelist(head);	
}
