/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:28:04 by murachid          #+#    #+#             */
/*   Updated: 2021/12/08 15:27:33 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	exe_cd(t_cmds *tmp)
{
	struct s_data_item	*temp;

	temp = NULL;
	if (!tmp->arguments[0])
	{	
		temp = search("HOME", temp);
		if (!temp)
			message_print_red("", "cd: HOME not set\n", 1);
		else
		{
			if (chdir(temp->data) == -1)
				perror("minishell");
		}
	}
	else if (chdir(tmp->arguments[0]) == -1)
		message_print_red(tmp->arguments[0], " No such file or directory\n", 1);
}

void	exe_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("minishell\n");
}
