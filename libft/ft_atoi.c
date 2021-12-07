/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:36:24 by murachid          #+#    #+#             */
/*   Updated: 2021/12/05 16:56:56 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cond(int abs)
{
	if (abs > 0)
		abs = -1;
	else
		abs = 0;
	return (abs);
}

int	ft_atoi(const char *str)
{
	int		abs;
	long	nbr;

	abs = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			abs = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (nbr < 0)
		return (ft_cond(abs));
	return (abs * nbr);
}
