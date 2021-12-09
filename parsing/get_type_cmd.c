/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:21:31 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**get_type_cmnd(char *line)
{
	char	**ret;

	ret = ft_split_plus(line, ' ');
	return (ret);
}

char	**type_ifred_else(char **str, char *type, char **split)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	type = NULL;
	while (str[j])
	{
		i = 0;
		while (str[j] && (str[j][i] == '<' || str[j][i] == '>'
				|| str[j][i] == ' '))
			i++;
		len = (1 + len_wrds((str[j] + i), ' '));
		if (len > 1)
		{
			split = ft_split_plus((str[j] + i), ' ');
			break ;
		}
		else
			j++;
	}
	return (split);
}

char	*get_type_cmnd_ifred_half(char	**split, char **str)
{
	char	**tmp_if;
	char	*type;

	type = NULL;
	tmp_if = type_ifred_else(str, type, split);
	if (tmp_if && tmp_if[1])
		type = ft_strdup(tmp_if[1]);
	else
		type = ft_strdup("");
	if (tmp_if)
		free_array(tmp_if);
	return (type);
}

char	*get_type_cmnd_ifred(char *line, char **str, int nbr)
{
	int		i;
	char	**tmp;
	char	*type;
	char	**split;

	i = 0;
	split = NULL;
	nbr = 0;
	type = "";
	while (line && line[i] == ' ')
		i++;
	if (line[i] != '<' && line[i] != '>')
	{
		tmp = get_type_cmnd(line);
		if (type && tmp[0])
			type = ft_strdup(tmp[0]);
		else
			type = ft_strdup("");
		if (tmp)
			free_array(tmp);
	}
	else
		type = get_type_cmnd_ifred_half(split, str);
	return (type);
}

char	**get_args_ifred(char *line, char **str, int j)
{
	char	**tmp;
	char	**ret;
	int		len;
	int		i;
	int		y;

	y = 0;
	j = 0;
	ret = NULL;
	len = 0;
	tmp = char_dbl_alloc(1);
	tmp[0] = NULL;
	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line[i] != '<' && line[i] != '>')
		tmp = get_args_ifred_if(len, ret, str, tmp);
	else
		tmp = get_args_ifred_else(y, str, tmp);
	return (tmp);
}
