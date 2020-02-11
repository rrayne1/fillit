//42header
#include "../includes/fillit.h"

void    ft_clearch(t_mas *mas, char a)
{
	int	i;

	i = 0;
	while (*(mas->sq[i]) == '.' || (*(mas->sq[i]) >= 'A' && *(mas->sq[i]) <= 'Z'))
	{
		if (ft_strchr(mas->sq[i], a) != NULL)
			*ft_strchr(mas->sq[i], a) = '.';
		else if (ft_strchr(mas->sq[i], a) == NULL)
			i++;
	}
}

void	ft_search(int s, t_ttpos *tmppos)
{
	if (tmppos->cord[0] <= s)
	{
		if (tmppos->cord[1] > s)
		{
			tmppos->cord[0]++;
			tmppos->cord[1] = 0;
		}
	}
	if (tmppos->cord[0] > s)
		tmppos->cord[0] = -1;
}

int	ft_reshotka(t_mas *mas, t_ttpos *tmppos, int s)
{
	if ((tmppos->y[0] + tmppos->cord[0]) > s && (tmppos->y[1] + tmppos->cord[0]) > s &&
		(tmppos->y[2] + tmppos->cord[0]) > s && (tmppos->y[3] + tmppos->cord[0]) > s)
		return (0);
	if ((tmppos->x[0] + tmppos->cord[1]) > s && (tmppos->x[1] + tmppos->cord[1]) > s &&
		(tmppos->x[2] + tmppos->cord[1]) > s && (tmppos->x[3] + tmppos->cord[1]) > s)
		return (0);
	if (mas->sq[tmppos->y[0] + tmppos->cord[0]][tmppos->x[0] + tmppos->cord[1]] != '.')
		return (0);
	if (mas->sq[tmppos->y[1] + tmppos->cord[0]][tmppos->x[1] + tmppos->cord[1]] != '.')
		return (0);
	if (mas->sq[tmppos->y[2] + tmppos->cord[0]][tmppos->x[2] + tmppos->cord[1]] != '.')
		return (0);
	if (mas->sq[tmppos->y[3] + tmppos->cord[0]][tmppos->x[3] + tmppos->cord[1]] != '.')
		return (0);
	return (1);
}

void	ft_headfree(t_list *head)
{
	t_ttpos		*tmppos;
	t_list		*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		tmppos = head->content;
		free(tmppos);
		free(head);
		head = tmp;
	}
}

void	ft_clearallmas(t_mas *mas, t_list *head)
{
	t_ttpos	*tmppos;

	while (head->next != NULL)
	{
		tmppos = head->content;
		if (tmppos->num != 0)
		{
			tmppos->cord[0] = 0;
			tmppos->cord[1] = 0;
			tmppos->num = 0;
			ft_clearch(mas, tmppos->simb);
		}
		head = head->next;
	}
}
