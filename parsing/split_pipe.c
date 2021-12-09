/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:22:16 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:04 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**more_splt(int *indexs, int j)
{
	t_cmds	*data;
	char	**str;
	int		*lenght;

	lenght = int_alloc(j);
	data = init_stuct();
	lenght[0] = indexs[0] + 1;
	str = more_splt_allc(j, indexs, lenght);
	str = more_splt_half(j, str, lenght, indexs);
	free(lenght);
	lenght = 0;
	return (str);
}

char	**split_one_cmnd(void)
{
	t_cmds	*data;
	char	**str;

	str = char_dbl_alloc(3);
	data = init_stuct();
	str[0] = ft_strdup(data->line);
	str[1] = NULL;
	return (str);
}

char	**split_line_pipe_if(char *s, int *indexs, int j, char **str)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			i = skip_d_sqts(++i, s);
		else if (s[i] == '\'')
			i = skip_s_sqts(++i, s);
		else if (s[i] == '|')
		{
			indexs[j] = i;
			j++;
		}
		i++;
	}
	indexs[j] = i;
	j++;
	if (j)
		str = more_splt(indexs, j);
	return (str);
}

int	get_lenght_by_char(char *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			i = skip_d_sqts(++i, s);
		else if (s[i] == '\'')
			i = skip_s_sqts(++i, s);
		else if (s[i] == c)
			len++;
		i++;
	}
	return (len);
}

char	**split_line_pipe(char *s)
{
	int		i;
	int		j;
	int		*indexs;
	char	**str;
	int		pipe_len;

	str = NULL;
	pipe_len = get_lenght_by_char(s, '|');
	indexs = int_alloc(pipe_len + 1);
	i = 0;
	j = 0;
	if (pipe_len > 0)
		str = split_line_pipe_if(s, indexs, j, str);
	else
		str = split_one_cmnd();
	free(indexs);
	indexs = 0;
	return (str);
}
