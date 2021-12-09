/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_util_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:14:11 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 00:16:45 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing_head.h"

void	list_envs(char **envs)
{
	int		i;
	char	**tmp;

	i = 0;
	while (envs[i])
	{
		if (tmp)
			tmp = ft_split(envs[i], '=');
		insert(tmp[0], tmp[1]);
		if (tmp)
			free_array(tmp);
		i++;
	}
}
