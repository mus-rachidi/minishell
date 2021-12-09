/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:45:48 by murachid          #+#    #+#             */
/*   Updated: 2021/12/09 22:21:02 by rel-bour         ###   ########.fr       */
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

typedef struct s_here_doc
{
	char	*s;
	int		fd1;
	int		fd2;
	char	*stor_a;
}t_here_doc;

int	file_descriptor(t_cmds *cmds, int zero, int i)
{
	t_here_doc	hd;
	t_cmds		*fl;
	t_cmds		*tmp1;

	tmp1 = cmds;
	fl = init_stuct();
	dup2(zero, 0);
	hd.stor_a = ft_itoa(i);
	hd.fd1 = open(hd.stor_a, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (fl->stop)
	{
		hd.s = readline("> ");
		if (!hd.s || !ft_strcmp(hd.s, tmp1->redrctions->org_name))
		{
			free_one(hd.s);
			break ;
		}
		write(hd.fd1, hd.s, ft_strlen(hd.s));
		write(hd.fd1, "\n", 1);
		free(hd.s);
	}
	close(hd.fd1);
	hd.fd2 = open(hd.stor_a, O_RDONLY);
	free(hd.stor_a);
	return (hd.fd2);
}
