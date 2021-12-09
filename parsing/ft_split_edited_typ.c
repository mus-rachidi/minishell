/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_edited_typ.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:21:02 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:52 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**alloc_ret_split(char **ret, char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = len_wrds(str, c);
	ret = char_dbl_alloc(len + 2);
	while (i < len + 1)
	{
		ret[i] = char_alloc(100);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*split_typecmd_half_dbl_qots(int *i, char *str, char c, char *rett)
{
	(*i)++;
	while (str[*i] && str[*i] != c)
	{
		rett = strjoin1(rett, str[*i]);
		(*i)++;
	}
	(*i)++;
	return (rett);
}

char	**edited_split_typecmd_half(char *str, char **ret, int j)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			ret[j] = split_typecmd_half_dbl_qots(&i, str, '\"', ret[j]);
		else if (str[i] == '\'')
			ret[j] = split_typecmd_half_dbl_qots(&i, str, '\'', ret[j]);
		else if (str[i] == ' ' || str[i] == '>' || str[i] == '<')
		{
			i++;
			while (str[i] && (str[i] == ' ' || str[i] == '>' || str[i] == '<'))
				i++;
		}
		else
		{
			ret[j] = strjoin1(ret[j], str[i]);
			j++;
			i++;
		}
	}
	return (ret);
}

char	**edited_split_typecmd(char *str, char c)
{
	int		i;
	char	**ret;
	int		j;

	ret = NULL;
	ret = alloc_ret_split(ret, str, c);
	i = 0;
	j = 0;
	ret[j] = ft_strdup("");
	str = ft_strtrim_space(str, " ");
	return (edited_split_typecmd_half(str, ret, j));
}

char	*strjoin1(char *s, char c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = char_alloc(len + 2);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}
