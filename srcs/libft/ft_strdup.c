/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:10:15 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 10:04:53 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*duplicate;

	i = 0;
	duplicate = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (duplicate);
	while (i < ft_strlen(s) + 1)
	{
		duplicate[i] = s[i];
		i++;
	}
	return (duplicate);
}
