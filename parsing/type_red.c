/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:22:54 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 23:57:34 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

char	**get_filename(char *str)
{
	int		j;
	char	**ret;

	j = 0;
	while (str[j] && (str[j] == '<' || str[j] == '>'
			|| str[j] == ' '))
		j++;
	ret = ft_split_plus((str + j), ' ');
	return (ret);
}

int	get_type_red(char *str)
{
	int	j;
	int	ret;

	j = 0;
	ret = -1;
	while (str[j] && str[j] == ' ')
		j++;
	if (str[j] == '>' && str[j + 1] != '>' )
		ret = 1;
	else if (str[j] == '<' && str[j + 1] != '<' )
		ret = 0;
	else if (str[j] == '>' && str[j + 1] == '>' )
		ret = 2;
	else if (str[j] == '<' && str[j + 1] == '<' )
		ret = 3;
	return (ret);
}

int	syntax_quotes(void)
{
	t_cmds	*data;
	int		i;

	i = 0;
	data = init_stuct();
	while (data->line[i])
	{
		if (syntax_quotes_half(&i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	syntax_errors(char **splitline, int type)
{
	if (type == 1)
		return (syntax_pipes(splitline));
	else if (type == 2)
		return (syntax_quotes());
	return (0);
}

int	check_emptyline(void)
{
	t_cmds	*data;
	int		i;

	data = init_stuct();
	i = 0;
	while (data->line[i] && data->line[i] == ' ')
		i++;
	if (data->line[i] == '\0')
		return (1);
	return (0);
}
