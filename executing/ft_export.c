/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:02:10 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 22:49:15 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

typedef struct s_export
{
	int			i;
	char		*key;
	char		*data;
}t_export;

void	exe_export_else(t_export p,	t_data_item	*d)
{
	export_util(d, p.data, p.key);
	free(p.key);
}

void	exe_export(t_cmds *tmp, struct s_data_item *temp)
{
	t_export	p;
	t_data_item	*d;

	p.i = 0;
	while (tmp->arguments[p.i])
	{
		p.key = key_export(tmp->arguments[p.i]);
		free_all(p.key);
		p.data = valeu_export(tmp->arguments[p.i]);
		if (error_export(p.key, tmp->arguments[p.i]) == 1)
		{
			p.i++;
			continue ;
		}
		d = search(p.key, temp);
		if (d && !p.data)
		{
			p.i++;
			free_one(p.key);
			continue ;
		}
		else
			exe_export_else(p, d);
		p.i++;
	}
}
