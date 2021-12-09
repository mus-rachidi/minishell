/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:48:04 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:12:14 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	*status_env_ret_qts(char *tmp, char *str, int j)
{
	char	*temp;
	char	*s;
	t_cmds	*data;
	char	*case_str;

	data = init_stuct();
	temp = tmp;
	case_str = ft_itoa(data->s_code);
	tmp = ft_strjoin(tmp, case_str);
	free(case_str);
	free(temp);
	s = ft_substr(str, (j), ft_strlen((str + (j))));
	temp = tmp;
	tmp = ft_strjoin(tmp, s);
	free(temp);
	free(str);
	free(s);
	return (tmp);
}

char	*status_env_ret(char *tmp, char *str, int j)
{
	char	*temp;
	char	*s;
	t_cmds	*data;
	char	*case_str;

	data = init_stuct();
	temp = tmp;
	case_str = ft_itoa(data->s_code);
	tmp = ft_strjoin(tmp, case_str);
	free(case_str);
	free(temp);
	s = ft_substr(str, (j), ft_strlen((str + (j))));
	temp = tmp;
	tmp = ft_strjoin(tmp, s);
	free(temp);
	free(str);
	free(s);
	return (tmp);
}

char	*ifqt_schange_env_while(int *j, char *str)
{
	if (str[*j] == '\'')
		(*j) = skip_s_sqts(++(*j), str);
	else if (str[*j] == '\"')
		str = change_env_dqots(str, j);
	return (str);
}

char	*change_env_while(char *str, int j, int j2)
{
	while ((unsigned int)j < (ft_strlen(str) - 1))
	{
		if (!str[j])
			break ;
		if ((str[j] == '\'' || str[j] == '\"'))
			str = ifqt_schange_env_while(&j, str);
		else if (str[j] == '$')
		{
			j = while_plus(j, str, &j2);
			if (!str[j])
				break ;
			else if (str[j] && str[j] == '?')
				str = change_env_no_qots(str, &j, j2);
			else if (true_condiftion(str, j))
			{
				j++;
				continue ;
			}
			else
				str = change_env_no_qots(str, &j, j2);
		}
		else
			j++;
	}
	return (str);
}

char	*change_env_dqots(char *str, int *j)
{
	int	j2;

	(*j)++;
	while (str[*j] && str[*j] != '\"')
	{
		if (str[*j] == '$')
		{
			j2 = (*j);
			while (str[*j] == '$')
				(*j)++;
			if (str[*j] && str[*j] == '?')
				str = change_env_half_qots(str, j, j2);
			else if ((!str[*j] || (!ft_isalpha(str[*j]) && str[*j] != '_')
					|| (str[*j] && !ft_isprint(str[*j]))))
			{
				(*j)++;
			}
			else
				str = change_env_half_qots(str, j, j2);
		}
		else
			(*j)++;
	}
	return (str);
}
