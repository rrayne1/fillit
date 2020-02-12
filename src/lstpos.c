/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:01:46 by ljonas            #+#    #+#             */
/*   Updated: 2020/01/20 15:01:58 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_gettrmn(char **ttrmn, t_list *head, int fd) //26 lines
{
	int		i;
	char	*tt;
	int		q;

	q = 0;
	i = 0;
	//head->next = NULL;
	while (get_next_line(fd, &tt))
	{
		ttrmn[i] = tt;
		if (i++ == 3)
		{
			get_next_line(fd, &tt);
			if (!(ft_checkttrmn(ttrmn)) || tt[0] != '\0')
				return (0);
			free(tt);
			ft_lstaddbackpos(head, ft_newpos(ttrmn, ('A' + q)));
			ft_cleartt(ttrmn);
			q++;
			i = 0;
		}
	}
	free(tt);
	if (i != 0 || (get_next_line(fd, &tt)) != 0)
		return (0);
	return (q);
}

void	ft_checkposx(t_ttpos *pos)
{
	int	i;
	int	a;

	i = 0;
	while (i < 4)
	{
		if (pos->x[i] <= pos->x[0] && pos->x[i] <= pos->x[1]
			&& pos->x[i] <= pos->x[2] && pos->x[i] <= pos->x[3])
		{
			a = pos->x[i];
			pos->x[0] = pos->x[0] - a;
			pos->x[1] = pos->x[1] - a;
			pos->x[2] = pos->x[2] - a;
			pos->x[3] = pos->x[3] - a;
		}
		i++;
		}
}

void	ft_checkposy(t_ttpos *pos)
{
	int	i;
	int	a;

	i = 0;
	while (i < 4)
	{
		if (pos->y[i] <= pos->y[0] && pos->y[i] <= pos->y[1]
			&& pos->y[i] <= pos->y[2] && pos->y[i] <= pos->y[3] && pos->y[i] > 0)
		{
			a = pos->y[i];
			pos->y[0] = pos->y[0] - a;
			pos->y[1] = pos->y[1] - a;
			pos->y[2] = pos->y[2] - a;
			pos->y[3] = pos->y[3] - a;
		}
		i++;
	}
}

t_ttpos		*ft_newpos(char **ttrmn, char a) //31 lines
{
	t_ttpos		*pos;
	int			i;
	int			j;
	int			n;

	if (!(pos = (t_ttpos *) malloc(sizeof(t_ttpos))))
		return (NULL);
	pos->simb = a;
	pos->num = 0;
	pos->cord[0] = 0;
	pos->cord[1] = 0;
	i = 0;
	n = 0;
	while (i != 4)
	{
        j = 0;
        while (j != 4)
        {
            if (ttrmn[i][j] == '#')
            {
                pos->y[n] = i;
                pos->x[n] = j;
                n++;
            }
        	j++;
        }
		i++;
	}
	ft_checkposx(pos);
	ft_checkposy(pos);
	return (pos);
}

void	ft_lstaddbackpos(t_list *head, t_ttpos *pos) 
{
	t_list	*tmp;

	if (pos->simb != 'A')
	{
		tmp = (t_list *) malloc(sizeof(t_list));
		while (head->next != NULL)
			head = head->next;
		tmp->content = pos;
		tmp->content_size = sizeof(pos);
		tmp->next = NULL;
		head->next = tmp;
	}
	else 
	{
		head->content = pos;
		head->content_size = sizeof(pos);
		head->next = NULL;
	}
}
