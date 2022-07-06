/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/05 16:12:15 by jsauvain         ###   ########.fr       */
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

sighandler_t	get_bin(int sig, int *i, int *nb)
{
	if (sig == SIGUSR1)
		i += power(2, nb % 8);
	nb++;
	return (0);
}
