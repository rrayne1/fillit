/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:48:24 by ljonas            #+#    #+#             */
/*   Updated: 2020/02/10 21:29:10 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_checkttrmn (char **ttrmn)
{
	if (!(ft_check1(ttrmn)))
		return (0);
	if (!(ft_check2(ttrmn)))
		return (0);
	if (!(ft_check3(ttrmn)))
		return (0);
	if (ft_neighbours(ttrmn) < 6)
		return (0);
	return (1);
}

int		ft_check1(char **ttrmn)
{
	if (ft_strchr(ttrmn[0], '#') != NULL
			&& ft_strchr(ttrmn[1], '#') == NULL
				&& (ft_strchr(ttrmn[2], '#') != NULL
					|| ft_strchr(ttrmn[3], '#') != NULL))
		return (0);
	if (ft_strchr(ttrmn[1], '#') != NULL
			&& ft_strchr(ttrmn[2], '#') == NULL
				&& ft_strchr(ttrmn[3], '#') != NULL)
		return (0);
	return (1);
}

int		ft_check2 (char **ttrmn)
{
	int i;
	int j;
	int a;
	
	a = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ttrmn[i][j] != '.' && ttrmn[i][j] != '#')
				return (0);
			if (ttrmn[i][j] == '#')
				a++;
			j++;
		}
		if (ttrmn[i][j])
			return (0);
		i++;
	}
	if (a != 4)
		return (0);
	return (1);
}

int		ft_check3(char **ttrmn)
{
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ttrmn[i][j] == '#' && ttrmn[i][j + 1] == '.')
			{
				j++;
				while (j < 4)
				{
					if (ttrmn[i][j] == '#')
						return (0);
					j++;
				}
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

int		ft_neighbours(char **ttrmn) //28 lines
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ttrmn[i][j] == '#')
			{
                if (i < 3 && ttrmn[i + 1][j] == '#')
                    n++;
                if (i > 0 && ttrmn[i - 1][j] == '#')
                    n++;
                if (j < 3 && ttrmn[i][j + 1] == '#')
                    n++;
                if (j > 0 && ttrmn[i][j - 1] == '#')
                    n++;
            }
			j++;
		}
		i++;
	}
	return (n);
}
