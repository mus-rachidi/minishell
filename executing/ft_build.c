/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:29 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 18:10:48 by murachid         ###   ########.fr       */
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

int	ft_serch_char(t_cmds *tmp)
{
	int	i;

	i = 0;
	if (tmp->arguments[0][i] == '+' || tmp->arguments[0][i] == '-')
		i++;
	while (tmp->arguments[0][i] != '\0')
	{
		if (!ft_isnum(tmp->arguments[0][i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit_utile(t_cmds *tpm)
{
	unsigned char	i;

	if (!tpm->arguments[0])
		exit(EXIT_SUCCESS);
	if (!ft_serch_char(tpm) && tpm->arguments[1])
	{
		message_print_red(tpm->arguments[0], " too many arguments\n", 1);
	}
	else if (ft_serch_char(tpm))
	{
		message_print_red(tpm->arguments[0],
			" numeric argument required\n", 255);
		exit(255);
	}
	else
	{
		i = (unsigned char)ft_atoi(tpm->arguments[0]);
		exit(i);
	}
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
		ft_exit_utile(tmp);
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
