/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_data_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:22:07 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/09 22:11:31 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**get_all_args(char **args, char *type)
{
	t_cmds	*data;
	char	**tmp;
	int		i;

	i = 0;
	data = init_stuct();
	tmp = char_dbl_alloc(1);
	tmp[0] = NULL;
	tmp = join2d(tmp, type);
	while (args && args[i])
	{
		tmp = join2d(tmp, args[i]);
		i++;
	}
	return (tmp);
}

t_cmds	*data_if_not_red(t_cmds *test)
{
	char	**type;

	type = get_type_cmnd(test->command);
	test->type = ft_strdup(type[0]);
	free_array(type);
	test->arguments = get_args(test->command);
	test->redrctions = NULL;
	return (test);
}

int	*get_indexs_rd(t_cmds *test, int *indexs_rd, int *i)
{
	int	k;

	k = 0;
	while (test->command[k] != '\0')
	{
		if (test->command[k] == '"')
				k = skip_d_sqts(++k, test->command);
		if (test->command[k] == '\'')
				k = skip_s_sqts(++k, test->command);
		if (test->command[k] == '>' || test->command[k] == '<')
		{
			indexs_rd[(*i)] = k;
			(*i)++;
			while (test->command[k + 1] && (test->command[k + 1] == '>'
					|| test->command[k + 1] == '<'))
				k++;
		}
		k++;
	}
	indexs_rd[(*i)] = k;
	(*i)++;
	return (indexs_rd);
}

t_filerdr	*init_header_list_rd(t_filerdr *org_list, int p, char **str)
{
	t_filerdr	*add_tmp;
	char		**tmp_name;

	add_tmp = org_list;
	if (p == 1)
	{
		add_tmp->all = ft_strdup(str[p]);
		tmp_name = get_filename(str[p]);
		add_tmp->name = ft_strdup(tmp_name[0]);
		free_array(tmp_name);
		add_tmp->type = get_type_red(str[p]);
		add_tmp->next = NULL;
	}
	return (org_list);
}

t_filerdr	*new_red_list(char *str)
{
	t_filerdr	*tmp;
	char		**tmp_name;
	t_cmds		*for_filename;

	for_filename = init_stuct();
	tmp = red_alloc(1);
	tmp->org_name = ft_strdup(for_filename->filenames[for_filename->i_fl]);
	tmp->ambiguous = is_ambiguous(for_filename->filenames[for_filename->i_fl]);
	for_filename->i_fl++;
	tmp->all = ft_strdup(str);
	tmp_name = get_filename(str);
	tmp->name = ft_strdup(tmp_name[0]);
	free_array(tmp_name);
	tmp->type = get_type_red(str);
	tmp->next = NULL;
	return (tmp);
}
