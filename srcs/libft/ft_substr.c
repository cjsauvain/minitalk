/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:33:15 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 10:06:10 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	j;

	j = 0;
	dst = NULL;
	if (start >= ft_strlen(s))
	{
		dst = malloc(1 * sizeof(char));
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	else if (len >= ft_strlen(s))
		dst = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else if (len < ft_strlen(s))
		dst = malloc ((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (s[start] && j < len)
		dst[j++] = s[start++];
	dst[j] = '\0';
	return (dst);
}
