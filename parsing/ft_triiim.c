/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triiim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 05:14:29 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 10:34:51 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	fthelp(int str, char const *c)
{
	int	i;

	i = 0;
	while (*c != '\0')
	{
		if (*c == (char)str)
			return (1);
		c++;
	}
	return (0);
}

char	*ft_strtrim_space(char const *s1, char const *set)
{
	char	*rslt;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (strdup(""));
	start = 0;
	end = strlen(s1);
	if (end == 0)
		return (strdup(""));
	i = 0;
	while (fthelp(s1[start], set))
		start++;
	while (fthelp(s1[end - 1], set) && end > start)
		end--;
	rslt = char_alloc(end - start + 1);
	while (i < (end - start))
	{
		rslt[i] = (char)s1[i + start];
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
