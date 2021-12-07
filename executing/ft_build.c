/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:29 by murachid          #+#    #+#             */
/*   Updated: 2021/12/05 16:11:58 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

char	**init_list(void)
{
	char	**exe;

	exe = malloc(sizeof(char *) * 8);
	exe[0] = ft_strdup("pwd");
	exe[1] = ft_strdup("exit");
	exe[2] = ft_strdup("echo");
	exe[3] = ft_strdup("cd");
	exe[4] = ft_strdup("export");
	exe[5] = ft_strdup("unset");
	exe[6] = ft_strdup("env");
	exe[7] = NULL;
	return (exe);
}

int	test_built_cmd(t_cmds *tmp)
{
	char	**exe;
	int		i;

	exe = init_list();
	i = 0;
	while (exe[i])
	{
		if (tmp->type && !ft_strcmp(exe[i], tmp->type))
			return (1);
		i++;
	}
	free_array(exe);
	return (0);
}

void	exec_built(t_cmds *tmp)
{
	struct s_data_item	*temp;

	temp = NULL;
	if (tmp->type && !ft_strcmp(tmp->type, "cd"))
		exe_cd(tmp);
	else if (tmp->type && !ft_strcmp(tmp->type, "unset"))
		exe_unset(tmp, temp);
	else if (tmp->type && !ft_strcmp(tmp->type, "export"))
	{
		if (tmp->arguments[0])
			exe_export(tmp, temp);
	}
	else if (tmp->type && !ft_strcmp(tmp->type, "exit"))
		exit(EXIT_SUCCESS);
}

void	exec_built_second(t_cmds *tmp)
{
	struct s_data_item	*temp;

	temp = NULL;
	if (tmp->type && !ft_strcmp(tmp->type, "export"))
	{
		if (!tmp->arguments[0])
			display(tmp, temp);
	}
	else if (tmp->type && !ft_strcmp(tmp->type, "env"))
		display(tmp, temp);
}
