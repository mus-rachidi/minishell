/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:51:31 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

t_cmds	*init_stuct(void)
{
	static t_cmds	*data;

	if (!data)
		data = cmd_alloc(1);
	return (data);
}

t_cmds	*new_node(char *str)
{
	t_cmds	*tmp;

	tmp = cmd_alloc(1);
	tmp->command = ft_strdup(str);
	tmp->type = NULL;
	tmp->arguments = NULL;
	tmp->all = NULL;
	tmp->next_cmd = NULL;
	return (tmp);
}

void	join_list(t_cmds *tmp, t_cmds *src)
{
	t_cmds	*ret;

	ret = tmp;
	while (ret->next_cmd != NULL)
		ret = ret->next_cmd;
	ret->next_cmd = src;
}

void	init_linkedlist(char **str)
{
	int		i;
	t_cmds	*data;
	t_cmds	*tmp;
	t_cmds	*src;

	data = init_stuct();
	tmp = data;
	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			tmp->command = ft_strdup(str[i]);
			tmp->type = NULL;
			tmp->arguments = NULL;
			tmp->all = NULL;
			tmp->next_cmd = NULL;
		}
		else
		{
			src = new_node(str[i]);
			join_list(tmp, src);
		}
		i++;
	}
}

void	clear_red_list(t_filerdr *f)
{
	if (f->name)
	{
		free(f->name);
		f->name = NULL;
	}
	if (f->all)
	{
		free(f->all);
		f->all = NULL;
	}
	if (f->org_name)
	{
		free(f->org_name);
		f->org_name = NULL;
	}
	f = f->next;
}
