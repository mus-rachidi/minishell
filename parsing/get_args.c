/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:21:21 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 00:09:54 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**ifred_if_half(char **tmp, char **ret, int i, char **str)
{
	int	len;
	int	y;

	y = 1;
	while (str && str[y])
	{
		i = 0;
		while (str[y][i] && (str[y][i] == ' ' || str[y][i] == '>'
				|| str[y][i] == '<'))
			i++;
		ret = ft_split_plus(str[y] + i, ' ');
		len = len_array(ret);
		if (len > 1)
		{
			i = 1;
			while (ret[i])
			{
				tmp = join2d(tmp, ret[i]);
				i++;
			}
		}
		y++;
		free_array(ret);
	}
	return (tmp);
}

char	**get_args_ifred_if(int len, char **ret, char **str, char **tmp)
{
	int	i;

	i = 0;
	if (str[0])
	{
		ret = ft_split_plus(str[0], ' ');
		len = len_array(ret);
		if (len > 1)
		{
			i = 1;
			while (i < (len))
			{
				tmp = join2d(tmp, ret[i]);
				i++;
			}
		}
	}
	tmp = ifred_if_half(tmp, ret, i, str);
	free_array(ret);
	return (tmp);
}

char	**args_red_else_half(char **tmp, int i, char **ret, int *cmd)
{
	i = 1;
	if ((*cmd) == 0)
	{
		i = i + 1;
		(*cmd) = 1;
	}
	while (ret[i])
	{
		tmp = join2d(tmp, ret[i]);
		i++;
	}
	return (tmp);
}

char	**args_red_else_half_noprbl(char **tmp, int i, char **ret, int *cmd)
{
	i = 1;
	if ((*cmd) == 0)
	{
		i = i + 1;
		(*cmd) = 1;
	}
	while (ret[i])
	{
		tmp = join2d(tmp, ret[i]);
		i++;
	}
	return (tmp);
}

char	**get_args_ifred_else(int y, char **str, char **tmp)
{
	int		cmd;
	int		len;
	char	**ret;
	int		i;

	cmd = 0;
	y = 0;
	while (str[y])
	{
		i = 0;
		while (str[y] && (str[y][i] == '<' || str[y][i] == '>'
			|| str[y][i] == ' '))
			i++;
		len = len_wrds((str[y] + i), ' ');
		if (len > 0)
		{
			ret = ft_split_plus((str[y] + i), ' ');
			tmp = args_red_else_half_noprbl(tmp, i, ret, &cmd);
			free_array(ret);
		}
		y++;
	}
	return (tmp);
}
