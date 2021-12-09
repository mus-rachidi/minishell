/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delet_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:20:41 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**alloc_ft_split(char **ret, char *str, char c)
{
	int	i;
	int	len;

	i = 1;
	len = len_wrds_edit(str, c);
	if (!len)
		len = 1;
	ret = char_dbl_alloc(len + 1);
	while (i < (len))
		i++;
	ret[i] = NULL;
	return (ret);
}

char	*ft_split_half_dbl_qots(int *i, char *str, char *ret, char c)
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

char	**ft_split_plus(char *str, char c)
{
	int		i;
	int		len;
	char	**ret;
	int		j;

	len = 0;
	ret = NULL;
	if (!str)
	{
		ret = NULL;
		return (ret);
	}
	i = 0;
	j = 0;
	ret = alloc_ft_split(ret, str, c);
	ret[j] = ft_strdup("");
	str = ft_strtrim_space(str, " ");
	ret = ft_split_plus_half(str, i, ret, j);
	free(str);
	str = NULL;
	return (ret);
}

int	edit_cmds(void)
{
	t_cmds	*data;
	t_cmds	*test;
	int		ret_value;
	char	**str;

	str = NULL;
	ret_value = 0;
	data = init_stuct();
	test = data;
	while (test != NULL)
	{
		if (if_redrction(test->command) == 1)
			test = data_if_red_exist(test, &ret_value);
		else
			test = data_if_not_red(test);
		test->all = get_all_args(test->arguments, test->type);
		test->option = is_there_option(test->type, test->arguments);
		test = test->next_cmd;
	}
	return (0);
}

int	valid_echo_option(char *arg)
{
	int	i;

	i = 0;
	if (arg && arg[i] == '-')
	{
		i++;
		if (arg[i] && arg[i] == 'n')
		{
			while (arg[i])
			{
				if (arg[i] != 'n')
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}
