/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:38:36 by murachid          #+#    #+#             */
/*   Updated: 2021/12/10 19:40:01 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	*ft_getenv(char *s)
{
	struct s_data_item	*p;

	p = NULL;
	p = search(s, p);
	if (!p)
		return (NULL);
	return (p->data);
}

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

t_free_stc	*init_struct_free(void)
{
	static t_free_stc	data;

	return (&data);
}

void	free_all(void *n)
{
	t_free		*tmp;
	t_free_stc	*p;

	p = init_struct_free();
	tmp = (t_free *)malloc(sizeof(t_free));
	tmp->next_t = (p->free_p);
	tmp->newt = n;
	p->free_p = tmp;
}
