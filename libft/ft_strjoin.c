/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:36:47 by rrayne            #+#    #+#             */
/*   Updated: 2019/10/30 16:32:25 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin (char const *s1, char const *s2) {
	char *str;
	size_t len;
	char *res;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *) malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	res = str;
	while (*s1) {
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2) {
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}
