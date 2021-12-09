/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:56:01 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 18:23:59 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_redrection(t_filerdr *f)
{
	t_filerdr	*tmp;

	while (f)
	{
		tmp = f;
		f = f->next;
		clear_red_list(tmp);
		free(tmp);
		tmp = NULL;
	}
}

void	clear_list_half(t_cmds *tmp, int j)
{
	if (tmp->arguments)
	{
		free(tmp->arguments);
		tmp->arguments = NULL;
	}
	j = 0;
	while (tmp->all && tmp->all[j])
	{
		free(tmp->all[j]);
		tmp->all[j] = NULL;
		j++;
	}
	free(tmp->all);
	tmp->all = NULL;
}

void	clear_list(t_cmds *tmp)
{
	int	j;

	j = 0;
	if (tmp->redrctions)
		free_redrection(tmp->redrctions);
	if (tmp->type)
	{
		free(tmp->type);
		tmp->type = NULL;
	}
	if (tmp->command)
	{
		free(tmp->command);
		tmp->command = NULL;
	}
	clear_list_half(tmp, j);
}

void	free_list(void)
{
	t_cmds	*data;
	t_cmds	*tmp;
	int		d;

	d = 0;
	data = init_stuct();
	while (data)
	{
		tmp = data;
		data = data->next_cmd;
		clear_list(tmp);
		if (d != 0)
			free(tmp);
		d++;
	}
}
