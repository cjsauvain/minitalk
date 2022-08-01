/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:51:48 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 10:03:46 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		i;
	int			j;

	i = ft_strlen(dst);
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(src) + ft_strlen(dst) - j);
}
