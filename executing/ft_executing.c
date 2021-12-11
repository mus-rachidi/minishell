/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:14:41 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 01:43:53 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

char	*ft_path_util(t_pipex *pipex, char *a, char *cmd)
{
	int		c;

	c = 0;
	c = check_mywrite();
	if (cmd)
	{
		ft_join(pipex, cmd);
		cmd = pipex->bin;
		return (pipex->bin);
	}
	else if (!cmd && !a && !c)
		message_print(cmd, ": No such file or directory\n", 127);
	return (NULL);
}

char	*ft_path(char *cmd, char *a)
{
	int					i;
	struct s_data_item	*temp;
	t_pipex				pipex;

	temp = NULL;
	i = 0;
	while (i < SIZE)
	{
		temp = g_hasharray[i];
		temp = search("PATH", temp);
		if (!temp)
			i++;
		else
		{
			pipex.path = temp->data;
			break ;
		}
	}
	if (!temp && !check_mywrite())
	{
		message_print(cmd, ": No such file or directory\n", 127);
		return (NULL);
	}
	else
		return (ft_path_util(&pipex, a, cmd));
}

void	exute_f(t_cmds *cmd, char *envs[])
{
	char	*a;
	int		c;

	c = 0;
	c = check_mywrite();
	a = NULL;
	if (cmd->redrctions)
		a = cmd->redrctions->name;
	if (!access(cmd->type, F_OK) && !ft_strncmp(cmd->type, "/", 1))
	{
		if (execve(cmd->type, cmd->all, envs) && !c)
			message_print(cmd->type, " is a directory\n", 127);
		else
			exit(0);
	}
	else
	{
		cmd->type = ft_path(cmd->type, a);
		execve(cmd->type, cmd->all, envs);
		exit(0);
	}
}

void	exec_cmd(t_cmds *cmd, char *envs[])
{
	int		c;

	c = 0;
	c = check_mywrite();
	if (((!ft_strncmp(".", cmd->type, 1) || !ft_strncmp(
					"/", cmd->type, 1)) && access(cmd->type, F_OK)) && !c)
		message_print(cmd->type, " No such file or directory\n", 127);
	else if ((!ft_strcmp("./", cmd->type) || !ft_strcmp(
				"../", cmd->type)) && !c)
		message_print(cmd->type, " is a directory\n", 126);
	else if ((!ft_strncmp("./", cmd->type, 2)
			&& !access(cmd->type, F_OK)) && !c)
	{
		if ((execve(cmd->type, cmd->all, envs)
				&& !access(cmd->type, X_OK)) && !c)
			message_print(cmd->type, " Permission denied\n", 0);
		else
			exit(0);
	}
	else
		exute_f(cmd, envs);
}

void	ft_executing_in_child(t_cmds *cmds, char **envs)
{
	t_cmds	*tmp;

	tmp = cmds;
	if (test_built_cmd(tmp) == 0)
		exec_cmd(tmp, envs);
	else
	{	
		if (tmp->type && !ft_strcmp(tmp->type, "echo"))
			exe_echo(tmp);
		else if (tmp->type && !ft_strcmp(tmp->type, "pwd"))
			exe_pwd();
		exit(0);
	}
}
