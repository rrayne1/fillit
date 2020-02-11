//42header
#include "../includes/fillit.h"

void	ft_printfsq(t_mas *mas, int s)
{
	int	i;

	i = 0;
	while (i <= s)
	{
		ft_putstr(mas->sq[i]);
		ft_putchar('\n');
		i++;
	}
	free(mas);
}

void	ft_sq(t_mas *mas, int a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a)
	{
		j = 0;
		while (j <= a)
		{
			mas->sq[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_fullttrm(t_mas *mas, t_ttpos *tmppos, int s) //40-43 87char
{
	if (tmppos->cord[0] != -1 && ft_reshotka(mas, tmppos, s) == 1)
	{
		mas->sq[tmppos->y[0] + tmppos->cord[0]][tmppos->x[0] + tmppos->cord[1]] = tmppos->simb;
		mas->sq[tmppos->y[1] + tmppos->cord[0]][tmppos->x[1] + tmppos->cord[1]] = tmppos->simb;
		mas->sq[tmppos->y[2] + tmppos->cord[0]][tmppos->x[2] + tmppos->cord[1]] = tmppos->simb;
		mas->sq[tmppos->y[3] + tmppos->cord[0]][tmppos->x[3] + tmppos->cord[1]] = tmppos->simb;
		return (1);
	}
	else if (tmppos->cord[0] != -1 && ft_reshotka(mas, tmppos, s) != 1)
		return (0);
	return (-1);
}

int		ft_fullsq(t_mas *mas, t_list *head, int q, int s)
{
	t_list		*tmp;
	t_ttpos		*tmppos;
	int			res;
	int			i;

	i = 0;
	tmp = head;
	while (q > i)
	{
		tmppos = (t_ttpos *) tmp->content;
		if (tmppos->num == 0)
		{
			ft_search(s, tmppos);
			res = ft_fullttrm(mas, tmppos, s);
			if (res == 1)
			{
				i++;
				tmppos->num = i;
				tmp->content = tmppos;
				if (tmp->next == NULL)
					tmp = head;
				else
					tmp = tmp->next;
			}
			else if (res == -1)
			{
				tmppos->cord[0] = 0;
				if (q - 6 > i)
				{
					ft_clearallmas(mas, head);
					return (0);
				}
				if (tmp->next == NULL)
				{
					if (tmp->next == NULL && i == 0)
						return (0);
					tmp = head;
				}
				else
					tmp = tmp->next;
			}
			else if (res == 0)
				tmppos->cord[1]++;
		}
		else if (tmppos->num == i)
		{
			i--;
			ft_clearch(mas, tmppos->simb);
			tmppos->num = 0;
			tmp->content = tmppos;
			tmppos->cord[1]++;
		}
		else if (tmppos->num != i && tmppos->num != 0)
		{
			if (tmp->next == NULL)
				tmp = head;
			else
				tmp = tmp->next;
		}
	}
	return (1);
}

void	ft_placettrm(t_list *head, int q)
{
	int		s;
	t_mas	*mas;

	mas = (t_mas *) malloc(sizeof(t_mas));
	ft_sqinit(mas);
	s = ft_sqrt(q) - 1;
	while (1)
	{
		ft_sq(mas, s);
		if (ft_fullsq(mas, head, q, s))
			break;
		s++;
	}
	ft_printfsq(mas, s);
}
