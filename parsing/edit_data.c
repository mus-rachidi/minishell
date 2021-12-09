/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:45:30 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	is_ambiguous(char *str)
{
	int		i;
	char	*temp;
	char	*ret;

	i = 1;
	if (str[0] && str[0] == '$')
	{
		if (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		{
			ret = ft_strdup("");
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			{
				temp = ret;
				ret = strjoin1(ret, str[i]);
				free(temp);
				i++;
			}
			if (is_ambiguous_exist(ret) == -1)
				return (amg_free(ret));
			if (ret)
				free(ret);
		}
	}
	return (0);
}

t_filerdr	*if_initial_red(t_filerdr *add_tmp, char **str)
{
	char		**tmp_name;
	t_cmds		*fl;

	fl = init_stuct();
	add_tmp->org_name = ft_strdup(fl->filenames[fl->i_fl]);
	add_tmp->ambiguous = is_ambiguous(fl->filenames[fl->i_fl]);
	fl->i_fl++;
	add_tmp->all = ft_strdup(str[1]);
	tmp_name = get_filename(str[1]);
	add_tmp->name = ft_strdup(tmp_name[0]);
	free_array(tmp_name);
	add_tmp->type = get_type_red(str[1]);
	add_tmp->next = NULL;
	return (add_tmp);
}

t_cmds	*initial_red_struct(t_cmds *test, char **str, int p)
{
	t_filerdr	*add_tmp;
	t_filerdr	*src;

	test->redrctions = red_alloc(1);
	add_tmp = test->redrctions;
	while (str[p])
	{
		if (p == 1)
			add_tmp = if_initial_red(add_tmp, str);
		else
		{
			src = new_red_list(str[p]);
			join_red_list(add_tmp, src);
		}
		p++;
	}
	return (test);
}

int	*dt_red_exist_alloc(t_cmds *test)
{
	int		red_len;
	int		*indexs_rd;

	red_len = (get_lenght_by_char(test->command, '>')
			+ get_lenght_by_char(test->command, '<'));
	indexs_rd = int_alloc(red_len + 1);
	return (indexs_rd);
}

t_cmds	*data_if_red_exist(t_cmds *test, int *ret_value)
{
	char	**str;
	int		i;
	int		*indexs_rd;
	int		p;
	int		*tmp;

	ret_value = 0;
	str = NULL;
	p = 1;
	i = 0;
	indexs_rd = dt_red_exist_alloc(test);
	indexs_rd = get_indexs_rd(test, indexs_rd, &i);
	tmp = indexs_rd;
	if (i > 1)
	{
		str = get_position(indexs_rd, i, test->command);
		test->type = get_type_cmnd_ifred(test->command, str, i);
		test->arguments = get_args_ifred(test->command, str, i);
		test = initial_red_struct(test, str, p);
	}
	free_array(str);
	free(tmp);
	return (test);
}
