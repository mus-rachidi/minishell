/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_qouts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:44:43 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 10:40:35 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	*addqouts_half(int i, char *ret, char *s)
{
	char	*tmp;

	if (s[i] == ' ')
	{
		tmp = ret;
		ret = strjoin1(ret, '\'');
		free(tmp);
		tmp = ret;
		ret = strjoin1(ret, s[i]);
		free(tmp);
		tmp = ret;
		ret = strjoin1(ret, '\'');
		free(tmp);
	}
	else
	{
		tmp = ret;
		ret = strjoin1(ret, s[i]);
		free(tmp);
	}
	return (ret);
}

char	*addqouts(char *s)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = strdup("");
	tmp = ret;
	ret = strjoin1(ret, '\'');
	free(tmp);
	while (s[i])
	{
		ret = addqouts_half(i, ret, s);
		i++;
	}
	tmp = ret;
	ret = strjoin1(ret, '\'');
	free(tmp);
	return (ret);
}

int	while_plus(int j, char *str, int *j2)
{
	while (str[j] == '$')
		j++;
	(*j2) = j;
	return (j);
}

int	is_there_option(char *type, char **arg)
{
	if (!strcmp(type, "echo"))
	{
		if (valid_echo_option(arg[0]))
			return (1);
	}
	return (0);
}

int	amg_free(char *s)
{
	if (s)
		free(s);
	return (-1);
}
