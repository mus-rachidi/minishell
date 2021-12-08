/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:20:00 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/08 00:02:48 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

void	free_filenames(void)
{
	t_cmds	*data;
	t_cmds	*tmp;
	int		j;

	data = init_stuct();
	tmp = data;
	j = 0;
	if (tmp->filenames)
	{
		while (tmp->filenames[j])
		{
			free(tmp->filenames[j]);
			tmp->filenames[j] = NULL;
			j++;
		}
		if (tmp->filenames)
		{
			free(tmp->filenames);
			tmp->filenames = NULL;
		}
	}
}

int	red_syntax_errors(char **splitline)
{
	int		i;
	int		j;
	char	**str;
	int		*tmp;

	tmp = NULL;
	j = 0;
	i = 0;
	while (splitline && splitline[j])
	{
		if (if_redrction(splitline[j]))
		{
			if (sytax_red_double(splitline[j]) == -1)
				return (-1);
			str = split_mode(splitline[j]);
			join_org_names_red(str);
			if (red_syntax_errors_free(str, tmp) == -1)
			{
				free_filenames();
				return (-1);
			}
		}
		j++;
	}
	return (0);
}

void	start_parcing_norm(char **envs)
{
	t_cmds	*data;

	data = init_stuct();
	edit_cmds();
	exec_cmd_test(data, envs);
	free_filenames();
	free_list();
}

int	start_parsing(char **envs)
{
	t_cmds	*data;
	char	**splitline;

	data = init_stuct();
	if (check_emptyline() || syntax_errors(NULL, 2) == -1)
		return (-1);
	splitline = split_line_pipe(data->line);
	if (syntax_errors(splitline, 1) == -1)
	{
		data->s_code = 258;
		free_array(splitline);
		return (-1);
	}
	if (red_syntax_errors(splitline) == -1)
	{
		data->s_code = 258;
		free_array(splitline);
		return (-1);
	}
	change_env(splitline);
	init_linkedlist(splitline);
	free_array(splitline);
	start_parcing_norm(envs);
	return (0);
}

int	main_parsing(char **envs)
{
	t_cmds	*data;

	data = init_stuct();
	data->i_fl = 0;
	data->filenames = NULL;
	if (data->s_code < 0)
		data->s_code = 0;
	data->line = readline("User@minishell> ");
	if (!data->line)
	{
		printf("exit\n");
		exit(0);
	}
	add_history(data->line);
	if (start_parsing(envs) == -1)
	{
		free(data->line);
		data->line = NULL;
		return (-1);
	}
	free(data->line);
	data->line = NULL;
	return (0);
}
