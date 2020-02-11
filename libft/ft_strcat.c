/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:53:28 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 20:16:19 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat (char *dest, const char *src) {
	int i;
	int k;

	i = 0;
	k = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0') {
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
