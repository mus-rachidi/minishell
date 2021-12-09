/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:22:35 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:10:58 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	check_syntax(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	s = ft_strtrim_space(s, " ");
	if (ft_strlen(s) == 0)
	{
		free(s);
		s = NULL;
		return (1);
	}
	free(s);
	s = NULL;
	return (0);
}

int	syntax_pipes(char **splitline)
{
	t_cmds	*data;
	int		j;
	int		len;

	j = 0;
	data = init_stuct();
	while (splitline[j])
	{
		len = check_syntax(splitline[j]);
		if (len == 1)
		{
			printf("syntax error near unexpected token 2\n");
			return (-1);
		}
		j++;
	}
	return (0);
}

int	syntax_s_sqts(int *i, char *s)
{
	int	j;

	j = 0;
	(*i)++;
	while (s[*i])
	{
		if (s[*i] == '\'')
			return (1);
		(*i)++;
	}
	return (0);
}

int	syntax_d_sqts(int *i, char *s)
{
	int	j;

	j = 0;
	(*i)++;
	while (s[*i])
	{
		if (s[*i] == '\"')
			return (1);
		(*i)++;
	}
	return (0);
}

int	syntax_quotes_half(int *i)
{
	t_cmds	*data;

	data = init_stuct();
	if (data->line[(*i)] == '"')
	{
		if (syntax_d_sqts(i, data->line) == 0)
		{
			printf("syntax error : not in subject \n");
			data->s_code = 258;
			return (-1);
		}
	}
	else if (data->line[(*i)] == '\'')
	{
		if (syntax_s_sqts(i, data->line) == 0)
		{
			printf("syntax error : not in subject \n");
			data->s_code = 258;
			return (-1);
		}
	}
	return (0);
}
