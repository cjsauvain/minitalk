/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/06 16:50:08 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	power(int nb, int power)
{
	int	n;

	n = nb;
	while (power)
	{
		nb *= n;
		power--;
	}
	return (nb);
}

void	get_bin(int sig)
{
	static int	i = 0;
	static int	nb = 0;

	if (sig == SIGUSR1)
		i += power(2, nb % 7);
	nb++;
	if (nb > 7 && i)
	{
		ft_printf("%d", i);
		i = 0;
		nb = 0;
	}
	else if (i == 0 && nb > 7)
	{
		ft_printf("\n");
		nb = 0;
	}
}
