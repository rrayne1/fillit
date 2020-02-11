/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:06:53 by rrayne            #+#    #+#             */
/*   Updated: 2019/10/17 17:09:07 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew (size_t size) {
	char *str;

	if (!(str = (char *) malloc(sizeof(char) * (size + 1))))
		return (0);
	while (size > 0) {
		str[size--] = '\0';
	}
	str[0] = '\0';
	return (str);
}
