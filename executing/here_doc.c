/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:45:48 by murachid          #+#    #+#             */
/*   Updated: 2021/12/11 02:50:51 by murachid         ###   ########.fr       */
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
typedef struct s_here
{
	t_here_doc	hd;
	t_cmds		*fl;
	t_cmds		*tmp1;
	char		*path;
}t_here;

int	file_descriptor(t_cmds *cmds, int zero, int i)
{
	t_here	a;

	a.tmp1 = cmds;
	a.fl = init_stuct();
	dup2(zero, 0);
	a.hd.stor_a = ft_itoa(i);
	a.path = ft_strjoin("/tmp/", a.hd.stor_a);
	a.hd.fd1 = open(a.path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		a.hd.s = readline("> ");
		if (!a.hd.s || !ft_strcmp(a.hd.s, a.tmp1->redrctions->org_name))
		{
			free_one(a.hd.s);
			break ;
		}
		write(a.hd.fd1, a.hd.s, ft_strlen(a.hd.s));
		write(a.hd.fd1, "\n", 1);
		free(a.hd.s);
	}
	close(a.hd.fd1);
	a.hd.fd2 = open(a.path, O_RDONLY);
	free(a.path);
	free(a.hd.stor_a);
	return (a.hd.fd2);
}
