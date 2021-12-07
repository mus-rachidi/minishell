/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:43:00 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 23:17:47 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	*ft_getenv(char *s)
{
	struct	s_data_item *p;
	p = search(s, p);
	if (!p)
		return (NULL);
	return (p->data);
}

char	*tmp_change_qots(char *str, int *j)
{
	char	*tmp;

	(*j)--;
	tmp = ft_substr(str, 0, (*j));
	(*j)++;
	return (tmp);
}

void	init_some_var_halfqts(char *str, int *j, char **r, char **t)
{
	*r = strdup("");
	*t = tmp_change_qots(str, j);
}

char	*ret_change_env_qts(t_env_no_qts evq, int *j, char *str, int j2)
{
	evq.data = ft_getenv(evq.ret);
	if (!evq.data)
		evq.data = "";
	evq.temp = evq.tmp;
	evq.tmp = ft_strjoin(evq.tmp, evq.data);
	free(evq.temp);
	evq.s = ft_substr(str, (*j), strlen((str + (*j))));
	evq.temp = evq.tmp;
	evq.tmp = ft_strjoin(evq.tmp, evq.s);
	free(evq.temp);
	(*j) = (j2 + (strlen(evq.data)));
	free(evq.ret);
	free(evq.s);
	free(str);
	return (evq.tmp);
}

char	*change_env_half_qots(char *str, int *j, int j2)
{
	t_env_no_qts	evq;
	t_cmds			*data;

	data = init_stuct();
	init_some_var_halfqts(str, j, &evq.ret, &evq.tmp);
	if (str[*j] && (ft_isalpha(str[*j]) || str[*j] == '_'))
	{
		while (str[*j] && (ft_isalnum(str[*j]) || str[*j] == '_'))
		{
			evq.temp = evq.ret;
			evq.ret = strjoin1(evq.ret, str[*j]);
			free(evq.temp);
			(*j)++;
		}
	}
	else if (str[*j] && str[*j] == '?')
	{
		(*j)++;
		str = status_env_ret_qts(evq.tmp, str, *j);
		free(evq.ret);
		(*j) = (j2 + (nbr_len(data->s_code) - 1));
		data->s_code = 0;
		return (str);
	}
	return (ret_change_env_qts(evq, j, str, j2));
}

char	*ret_chng_env(t_env_no_qts ev, int *j, char *str, int j2)
{
	ev.data_alloc = 0;
	ev.data = ft_getenv(ev.ret);
	if (!ev.data)
		ev.data = "";
	else
	{
		ev.data = addqouts(ev.data);
		ev.data_alloc = 1;
	}
	ev.temp = ev.tmp;
	ev.tmp = ft_strjoin(ev.tmp, ev.data);
	free(ev.temp);
	ev.s = ft_substr(str, (*j), strlen((str + (*j))));
	ev.temp = ev.tmp;
	ev.tmp = ft_strjoin(ev.tmp, ev.s);
	free(ev.temp);
	(*j) = (j2 + (strlen(ev.data) - 1));
	free(ev.ret);
	if (ev.data_alloc == 1)
		free(ev.data);
	free(ev.s);
	free(str);
	return (ev.tmp);
}
