/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_split_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:09:01 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	len_wrds_alloc_split_mode(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	str = ft_strtrim_space(str, " ");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			i = skip_d_sqts(++i, str);
		else if (str[i] == '\'')
			i = skip_s_sqts(++i, str);
		else if (str[i] == '>' || str[i] == '<')
		{
			len = len + 1;
			while (str[i] && (str[i] == '>' || str[i] == '<'))
				i++;
			continue ;
		}
		i++;
	}
	free(str);
	str = NULL;
	return (len);
}

char	**alloc_split_mode(char **ret, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = len_wrds_alloc_split_mode(str);
	ret = char_dbl_alloc(len + 2);
	while (i < (len + 1))
	{
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*else_split_mode_half(char *ret, int *i, char c)
{
	char	*tmp;

	tmp = ret;
	ret = strjoin1(ret, c);
	free(tmp);
	(*i)++;
	return (ret);
}

char	**split_mode_half(char *str, int i, char **ret)
{
	int		j;

	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			ret[j] = split_mode_dbl_qots(&i, str, ret[j], '\"');
		else if (str[i] == '\'')
			ret[j] = split_mode_dbl_qots(&i, str, ret[j], '\'');
		else if (str[i] == '>' || str[i] == '<')
		{
			i++;
			while (str[i] && (str[i] == '>' || str[i] == '<'))
				i++;
			j++;
			ret[j] = ft_strdup("");
		}
		else
			ret[j] = else_split_mode_half(ret[j], &i, str[i]);
	}
	free(str);
	str = NULL;
	return (ret);
}

char	**split_mode(char *str)
{
	int		i;
	int		j;
	char	**ret;

	ret = NULL;
	ret = alloc_split_mode(ret, str);
	i = 0;
	j = 0;
	ret[0] = ft_strdup("");
	str = ft_strtrim_space(str, " ");
	return (split_mode_half(str, i, ret));
}
