/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/24 10:54:00 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

int	get_string(int sig, char *str)
{
	static int	i = 0;
	static int	nb = 0;

	str[i] += power(2, nb, sig);
	nb++;
	if (nb > 7 && str[i])
	{
		i++;
		nb = 0;
	}
	else if (nb > 7 && str[i] == 0)
	{
		ft_printf("%s\n", str);
		i = 0;
		nb = 0;
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

void	get_bin(int sig)
{
	static int	i = 0;
	static int	nb = 0;
	static char	*str = NULL;

	if (nb <= 31)
	{
		i += power(2, nb, sig);
		nb++;
	}
	else
	{
		if (i)
		{
			str = ft_calloc(i, sizeof(char));
			if (str == NULL)
			{
				ft_printf("Error : Malloc could not be done.");
				exit(1);
			}
			i = 0;
		}
		if (get_string(sig, str) == 1)
			nb = 0;
	}
}
