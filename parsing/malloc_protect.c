/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_protect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:47:27 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 21:37:48 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**char_dbl_alloc(int i)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * i);
	if (!str)
	{
		printf("malloc failed to allocate memory\n");
		exit (1);
	}
	return (str);
}

char	*char_alloc(int i)
{
	char	*str;

	str = (char *)malloc(sizeof(char ) * i);
	if (!str)
	{
		printf("malloc failed to allocate memory\n");
		exit (1);
	}
	return (str);
}

int	*int_alloc(int i)
{
	int	*str;

	str = (int *)malloc(sizeof(int ) * i);
	if (!str)
	{
		printf("malloc failed to allocate memory\n");
		exit (1);
	}
	return (str);
}

t_filerdr	*red_alloc(int i)
{
	t_filerdr	*list;

	list = (t_filerdr *)malloc(sizeof(t_filerdr) * i);
	free_all(list);
	if (!list)
	{
		printf("malloc failed to allocate memory\n");
		exit (1);
	}
	return (list);
}

t_cmds	*cmd_alloc(int i)
{
	t_cmds	*list;

	list = (t_cmds *)malloc(sizeof(t_cmds) * i);
	if (!list)
	{
		printf("malloc failed to allocate memory\n");
		exit (1);
	}
	return (list);
}
