/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:48:26 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 10:35:12 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	ifsplitis(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	skip_s_sqts(int i, char *s)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != '\'')
		i++;
	return (i);
}

int	skip_d_sqts(int i, char *s)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != '"')
		i++;
	return (i);
}

char	**more_splt_allc(int j, int *indexs, int *lenght)
{
	int		i;
	char	**str;

	i = 0;
	str = char_dbl_alloc(j + 1);
	while (i < j)
	{
		if (i > 0)
			lenght[i] = indexs[i] - indexs[i - 1];
		str[i] = char_alloc(1024);
		i++;
	}
	return (str);
}

char	**more_splt_half(int j, char **str, int *lenght, int *indexs)
{
	t_cmds	*data;
	int		y;
	int		d;
	int		i;

	d = 0;
	i = 0;
	data = init_stuct();
	while (i < j)
	{
		y = 0;
		while (y < lenght[i] - 1)
		{
			str[i][y] = data->line[d];
			y++;
			d++;
		}
		str[i][y] = '\0';
		d = 1 + indexs[i];
		i++;
	}
	str[i] = NULL;
	return (str);
}
