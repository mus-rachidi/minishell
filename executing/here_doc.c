/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:45:48 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 12:12:43 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

int	file_descriptor(t_cmds *cmds, int zero)
{
	char	*s;
	int		fd1;
	int		fd2;
	t_cmds	*fl;
	t_cmds	*tmp1;
	tmp1 = cmds;
	fl = init_stuct();
	dup2(zero, 0);
	fd1 = open("/tmp/tmp1", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (fl->stop)
	{
		s = readline("> ");
		if (!s || !strcmp(s, tmp1->redrctions->org_name))
			break ;
		write(fd1, s, ft_strlen(s));
		write(fd1, "\n", 1);
		free(s);
	}
	close(fd1);
	fd2 = open("/tmp/tmp1", O_RDONLY);
	return (fd2);
}
