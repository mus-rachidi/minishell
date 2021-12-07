/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:27:05 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 22:51:25 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**get_position_half(int i, t_index pos, int *i_rd, char *cmd)
{
	int	j;
	int	d;
	int	y;

	j = 0;
	d = 0;
	while (j < i)
	{
		y = 0;
		while (y < pos.lenght[j])
		{
			pos.str[j][y] = cmd[d];
			y++;
			d++;
		}
		pos.str[j][y] = '\0';
		d = i_rd[j];
		j++;
	}
	pos.str[j] = NULL;
	return (pos.str);
}

char	**get_position(int *indexs_rd, int i, char *cmd)
{
	t_index	pos;
	t_cmds	*data;

	pos.j = 0;
	pos.str = char_dbl_alloc(i + 1);
	pos.lenght = int_alloc(i);
	data = init_stuct();
	pos.lenght[0] = indexs_rd[0] + 1;
	while (pos.j < i)
	{
		if (pos.j > 0)
			pos.lenght[pos.j] = indexs_rd[pos.j] - indexs_rd[pos.j - 1];
		pos.str[pos.j] = char_alloc(1024);
		pos.j++;
	}
	pos.str = get_position_half(i, pos, indexs_rd, cmd);
	free(pos.lenght);
	pos.lenght = 0;
	return (pos.str);
}

char	**get_args(char *line)
{
	int		i;
	int		len;
	char	**ret;
	char	**tmp;

	ret = ft_split_plus(line, ' ');
	len = len_array(ret);
	tmp = char_dbl_alloc(1);
	tmp[0] = NULL;
	i = 1;
	if (len > 1)
	{
		while (ret[i])
		{
			tmp = join2d(tmp, ret[i]);
			i++;
		}
	}
	free_array(ret);
	return (tmp);
}

char	*ret_change_env_half_qots(char *str, int *j)
{
	char	*temp;
	char	*ret;

	ret = strdup("");
	temp = ret;
	ret = strjoin1(ret, str[*j]);
	free(temp);
	return (ret);
}
