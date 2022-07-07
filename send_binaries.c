/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_binaries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:41 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/07 08:57:55 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_binaries(pid_t pid, char *c)
{
	int	i;

	while (*c)
	{
		i = 6;
		while (i >= 0)
		{
			if ((*c >> i & 1) == 0)
				kill(pid, SIGUSR2);
			else if ((*c >> i & 1) == 1)
				kill(pid, SIGUSR1);
			usleep(50);
			i--;
		}
		c++;
	}
	while (i <= 6)
	{
		kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}
