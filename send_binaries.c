/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_binaries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:41 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/05 15:34:21 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_binaries(int pid, char *c)
{
	int	i;

	while (*c)
	{
		i = 7;
		while (i >= 0)
		{
			if (*c >> i & 1 == 0)
				kill(pid, SIGUSR1);
			else if (*c >> i & 1 == 1)
				kill(pid, SIGUSR2);
			i--;
		}
		c++;
	}
}
