/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:45:48 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 22:12:41 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing_head.h"

void	free_one(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

int	file_descriptor(t_cmds *cmds, int zero, int i)
{
	char	*s;
	int		fd1;
	int		fd2;
	t_cmds	*fl;
	t_cmds	*tmp1;
	char	*stor_a;
	tmp1 = cmds;
	fl = init_stuct();
	dup2(zero, 0);
	stor_a = ft_itoa(i);
	fd1 = open(stor_a, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (fl->stop)
	{
		s = readline("> ");
		if (!s || !ft_strcmp(s, tmp1->redrctions->org_name))
		{
			free_one(s);
			break ;
		}
		write(fd1, s, ft_strlen(s));
		write(fd1, "\n", 1);
		free(s);
	}
	close(fd1);
	fd2 = open(stor_a, O_RDONLY);
	free(stor_a);
	return (fd2);
}
