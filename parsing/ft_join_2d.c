/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:20:55 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 10:34:45 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	len_array(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

char	**join2d(char **args, char *s)
{
	char	**ret;
	int		i;

	ret = char_dbl_alloc(len_array(args) + 2);
	i = 0;
	while (i < (len_array(args)))
	{
		ret[i] = strdup(args[i]);
		i++;
	}
	if (!s)
		ret[i] = strdup("");
	else
		ret[i] = strdup(s);
	i++;
	ret[i] = NULL;
	free_array(args);
	return (ret);
}

void	join_red_list(t_filerdr *add_tmp, t_filerdr *src)
{
	t_filerdr	*ret;

	ret = add_tmp;
	while (ret->next != NULL)
		ret = ret->next;
	ret->next = src;
}

int	is_ambiguous_exist(char *s)
{
	char	*env_value;
	int		len;

	len = 0;
	env_value = getenv(s);
	if (!env_value)
		return (-1);
	len = len_wrds(env_value, ' ');
	if (len > 0)
		return (-1);
	return (0);
}

char	*else_org_split_typecmd_half(char *ret, int *i, char c)
{
	char	*tmp;

	tmp = ret;
	ret = strjoin1(ret, c);
	free(tmp);
	(*i)++;
	return (ret);
}
