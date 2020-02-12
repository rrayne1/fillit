/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:44:16 by ljonas            #+#    #+#             */
/*   Updated: 2020/02/10 16:44:22 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_sqinit(t_mas *mas)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 14)
	{
		j = 0;
		while (j <= 14)
		{
			mas->sq[i][j] = '\0';
			j++;
		}
		i++;
	}
}

int		ft_sqrt(int q)
{
	int	a;

	a = 1;
	q = q * 4;
	while ((a * a) < q)
		a++;
	return (a);
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
