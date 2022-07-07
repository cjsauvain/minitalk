/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/07 09:01:38 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	power(int nb, int power)
{
	int	n;

	n = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= n;
		power--;
	}
	return (nb);
}

void	get_bin(int sig)
{
	static int	i = 0;
	static int	nb = 6;

	if (sig == SIGUSR1)
		i += power(2, nb);
	nb--;
	if (nb < 0 && i)
	{
		ft_printf("%c", i);
		i = 0;
		nb = 6;
	}
	else if (nb < 0 && !i)
	{
		ft_printf("\n");
		nb = 6;
	}
}
