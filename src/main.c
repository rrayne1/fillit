/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:18:13 by ljonas            #+#    #+#             */
/*   Updated: 2020/02/10 13:55:08 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int ac, char **av)
{
	int			fd;
	int			q;
	char		**ttrmn;
	t_list		*head;

	if (!(head = (t_list *) malloc(sizeof(t_list)))
		|| ac != 2 || !(ttrmn = (char **) malloc(sizeof(char *) * 4)))
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	q = ft_gettrmn(ttrmn, head, fd);
	free(ttrmn);
	if (q == 0 || q > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_placettrm(head, q);
	ft_headfree(head);
	close(fd);
	return (0);
}
