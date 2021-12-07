/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:22:24 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 23:58:39 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	if_redrction(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i = skip_s_sqts(++i, s);
		if (s[i] == '\"')
			i = skip_d_sqts(++i, s);
		if (s[i] == '<' || s[i] == '>')
			return (1);
		i++;
	}
	return (0);
}

int	red_syntax_errors_free(char **str, int *tmp)
{
	tmp = 0;
	if (syntax_dyal_red(str) == -1)
	{
		free_array(str);
		return (-1);
	}
	free_array(str);
	return (0);
}

int	error_syntax_diff(char *str, int i, int len)
{
	if (len == 2)
	{
		if ((str[i] == '<' && str[i + 1] == '>')
			|| (str[i] == '>' && str[i + 1] == '<'))
		{
			printf("syntax error : '>' \n");
			return (-1);
		}
	}
	return (0);
}

int	error_return_syntax(int len, int i, char *str)
{
	if (len > 2)
	{
		printf("syntax error : '>' \n");
		return (-1);
	}
	if (error_syntax_diff(str, (i - len), len) == -1)
		return (-1);
	return (0);
}

char	*split_mode_dbl_qots(int *i, char *str, char *ret, char c)
{
	char	*tmp;

	(*i)++;
	while (str[*i] && str[*i] != c)
	{
		tmp = ret;
		ret = strjoin1(ret, str[*i]);
		free(tmp);
		(*i)++;
	}
	(*i)++;
	return (ret);
}
