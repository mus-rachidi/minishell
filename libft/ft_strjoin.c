/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:28:32 by murachid          #+#    #+#             */
/*   Updated: 2021/12/05 16:43:33 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (&strjoin[0] == 0)
		return (0);
	ft_strcpy(&strjoin[0], s1);
	ft_strcpy(&strjoin[size_s1], s2);
	return (strjoin);
}
