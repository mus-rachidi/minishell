/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:37:16 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/06 00:12:25 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**join2d_filenames(char **args, char *s)
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
	return (ret);
}

int	sytax_red_double(char *str)
{
	int	i;
	int	len;

	i = 0;
	while ((unsigned int)i < (strlen(str) - 1))
	{
		len = 0;
		if (str[i] == '"')
		i = skip_d_sqts(++i, str);
		if (str[i] == '\'')
				i = skip_s_sqts(++i, str);
		if (str[i] == '>' || str[i] == '<')
		{
			while (str[i] && (str[i] == '>' || str[i] == '<'))
			{
				len++;
				i++;
			}
			if (error_return_syntax(len, i, str) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	join_org_names_red(char **str)
{
	t_cmds	*data;
	int		i;
	char	**sp;
	char	**tmp;

	i = 1;
	data = init_stuct();
	while (str[i])
	{
		sp = edited_split(str[i], ' ');
		tmp = data->filenames;
		data->filenames = join2d_filenames(data->filenames, sp[0]);
		free_array(tmp);
		free_array(sp);
		i++;
	}
}
