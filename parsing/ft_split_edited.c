/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_edited.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:21:09 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	len_wrds(char *str, char c)
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
		else if (str[i] == c)
		{
			len = len + 1;
			while (str[i] && str[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	free(str);
	str = NULL;
	return (len);
}

char	**org_alloc_ret_split(char **ret, char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = len_wrds(str, c);
	ret = char_dbl_alloc(len + 2);
	while (i < (len + 1))
	{
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*org_typecmd_half_dbl_qots(int *i, char *str, char *ret, char c)
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

char	**org_split_typecmd_half(char *str, char c, int i, char **ret)
{
	int		j;

	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			ret[j] = org_typecmd_half_dbl_qots(&i, str, ret[j], '\"');
		else if (str[i] == '\'')
			ret[j] = org_typecmd_half_dbl_qots(&i, str, ret[j], '\'');
		else if (str[i] == c)
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			j++;
			ret[j] = ft_strdup("");
		}
		else
			ret[j] = else_org_split_typecmd_half(ret[j], &i, str[i]);
	}
	free(str);
	str = NULL;
	return (ret);
}

char	**edited_split(char *str, char c)
{
	int		i;
	int		j;
	char	**ret;

	ret = NULL;
	ret = org_alloc_ret_split(ret, str, c);
	i = 0;
	j = 0;
	ret[0] = ft_strdup("");
	str = ft_strtrim_space(str, " ");
	while (str && str[i] == ' ')
		i++;
	return (org_split_typecmd_half(str, c, i, ret));
}
