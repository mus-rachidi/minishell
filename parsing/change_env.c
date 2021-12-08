/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:58:28 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/08 00:02:19 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	true_condiftion(char *str, int j)
{
	if ((!ft_isalpha(str[j]) && str[j] != '_')
		|| (str[j] && !ft_isprint(str[j])))
		return (1);
	return (0);
}

char	*tmp_change_env_no_qots(char *str, int *j)
{
	char	*tmp;

	(*j)--;
	tmp = ft_substr(str, 0, (*j));
	(*j)++;
	return (tmp);
}

void	init_some_var(char *str, int *j, char **r, char **t)
{
	*r = strdup("");
	*t = tmp_change_env_no_qots(str, j);
}

char	*change_env_no_qots(char *str, int *j, int j2)
{
	t_env_no_qts	ev;
	t_cmds			*data;

	data = init_stuct();
	init_some_var(str, j, &ev.ret, &ev.tmp);
	if (str[*j] && (ft_isalpha(str[*j]) || str[*j] == '_'))
	{
		while (str[*j] && (ft_isalnum(str[*j]) || str[*j] == '_'))
		{
			ev.temp = ev.ret;
			ev.ret = strjoin1(ev.ret, str[*j]);
			free(ev.temp);
			(*j)++;
		}
	}
	else if (str[*j] && str[*j] == '?')
	{
		(*j)++;
		str = status_env_ret(ev.tmp, str, *j);
		free(ev.ret);
		(*j) = (j2 + (nbr_len(data->s_code) - 1));
		data->s_code = 0;
		return (str);
	}
	return (ret_chng_env(ev, j, str, j2));
}

char	**change_env(char **str)
{
	int	i;
	int	j;
	int	j2;

	i = 0;
	j2 = 0;
	while (str[i])
	{
		j = 0;
		str[i] = change_env_while(str[i], j, j2);
		i++;
	}
	return (str);
}
