/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_space_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:24:21 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 00:13:36 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	len_wrds_edit_half(int i, char *str)
{
	while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
	{
		if (str[i] == '\"')
			i = skip_d_sqts(++i, str);
		else if (str[i] == '\'')
			i = skip_s_sqts(++i, str);
		i++;
	}
	return (i);
}

int	len_wrds_edit(char *str, char c)
{
	int	i;
	int	len;

	c = 0;
	if (!str)
		return (0);
	i = 0;
	len = 0;
	str = ft_strtrim_space(str, " ");
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '<' && str[i] != '>')
		{
			len = len + 1;
			i = len_wrds_edit_half(i, str);
		}
		else
			i++;
	}
	free(str);
	str = NULL;
	return (len);
}

char	**split_plus_elsen(int *i, char *str, int *j, char **ret)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '>' || str[*i] == '<'))
		(*i)++;
	if (str[*i])
	{
		(*j)++;
		ret[*j] = strdup("");
	}
	return (ret);
}

char	*split_plus_return(char *str, int i, char *ret)
{
	char	*tmp;

	tmp = ret;
	ret = strjoin1(ret, str[i]);
	free(tmp);
	return (ret);
}

char	**ft_split_plus_half(char *str, int i, char **ret, int j)
{
	while (str[i] != '\0')
	{
		if (str[i] && (str[i] != ' ' && str[i] != '>' && str[i] != '<'))
		{
			while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
			{
				if (str[i] == '\"')
				{
					ret[j] = ft_split_half_dbl_qots(&i, str, ret[j], '\"');
					continue ;
				}
				else if (str[i] == '\'')
				{
					ret[j] = ft_split_half_dbl_qots(&i, str, ret[j], '\'');
					continue ;
				}
				else
					ret[j] = split_plus_return(str, i, ret[j]);
				i++;
			}
		}
		else
			ret = split_plus_elsen(&i, str, &j, ret);
	}
	return (ret);
}
