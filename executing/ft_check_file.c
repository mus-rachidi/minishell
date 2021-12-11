/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:44:11 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 01:44:39 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	check_mywrite(void)
{
	char	*buffer;
	int		res;
	int		fd;

	buffer = malloc(4);
	fd = open("/tmp/s_code", O_RDONLY, 0666);
	read(fd, buffer, 3);
	res = ft_atoi(buffer);
	free(buffer);
	return (res);
}
