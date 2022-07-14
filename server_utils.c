/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:45:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/14 17:15:37 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*ft_calloc(int nmemb, int size)
{
	int		i;
	void	*calloc;
	char	*cast;

	i = 0;
	ft_printf("%d\n", size);
	if ((size > 0 && size <= 2147483647) || (nmemb > 0 && nmemb <= 2147483647))
	{
		calloc = malloc(nmemb * size);
		cast = calloc;
		if (calloc == NULL)
			return (calloc);
		while (i < nmemb * size)
		{
			cast[i] = 0;
			i++;
		}
		return (calloc);
	}
	return (NULL);
}

int	power(int nb, int power, int sig)
{
	int	n;

	n = nb;
	if (sig == SIGUSR2)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= n;
		power--;
	}
	return (nb);
}
