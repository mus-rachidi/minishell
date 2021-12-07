/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:22:47 by rel-bour          #+#    #+#             */
/*   Updated: 2021/12/05 10:41:49 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_head.h"

int	syntax_len_wrds_half(char *str, int i, char c, int len)
{
	if (str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		i++;
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		i++;
	}
	else if (str[i] == c)
	{
		len = len + 1;
		i++;
		while (str[i] == ' ')
			i++;
	}
	else
		i++;
	return (i);
}

int	syntax_len_wrds(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	str = ft_strtrim_space(str, " ");
	if (str[i] != '\0')
		len++;
	while (str[i] && str[i] != '\0')
		i = syntax_len_wrds_half(str, i, c, len);
	free(str);
	str = NULL;
	return (len);
}

int	syntax_dyal_red_half(char **str, int i, int j)
{
	while (str[j])
	{
		while (str[j][i] && (str[j][i] == '<' || str[j][i] == '>'))
			i++;
		if (i > 2)
		{
			printf("syntax error : '>' \n");
			return (-1);
		}
		if (i == 2)
		{
			if ((str[j][0] == '>' && str[j][1] == '<') ||
				(str[j][0] == '<' && str[j][1] == '>'))
			{
				printf("syntax error : '>' \n");
				return (-1);
			}
		}
		j++;
	}
	return (0);
}

int	syntax_dyal_red(char **str)
{
	int	j;
	int	i;
	int	len;

	j = 1;
	i = 0;
	if (syntax_dyal_red_half(str, i, j) == -1)
		return (-1);
	while (str[j])
	{
		i = 0;
		while (str[j][i] && (str[j][i] == '<' ||
				str[j][i] == '>' || str[j][i] == ' '))
			i++;
		len = (syntax_len_wrds((str[j] + i), ' '));
		if (len == 0)
		{
			printf("syntax error near unexpected token 1\n");
			return (-1);
		}
		j++;
	}
	return (0);
}

int	nbr_len(int n)
{
	int		size;
	long	nb;

	nb = n;
	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}
