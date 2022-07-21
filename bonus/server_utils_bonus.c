/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:45:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/18 15:34:01 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
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

void	*ft_calloc(int nmemb)
{
	int		i;
	void	*calloc;
	char	*cast;

	i = 0;
	if (nmemb > 0 && nmemb <= 2147483647)
	{
		calloc = malloc(nmemb * sizeof(char));
		cast = calloc;
		if (calloc == NULL)
			return (calloc);
		while (i < nmemb)
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
