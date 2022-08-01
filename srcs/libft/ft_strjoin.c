/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:33:20 by jsauvain          #+#    #+#             */
/*   Updated: 2022/08/01 11:41:08 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char s2)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (dst == NULL)
		return (dst);
	if (s1)
	{
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
	}
	dst[i++] = s2;
	dst[i] = '\0';
	free(s1);
	s1 = NULL;
	return (dst);
}
