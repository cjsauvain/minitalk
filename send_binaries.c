/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_binaries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:41 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/14 16:37:05 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_lenght(pid_t pid, char *c)
{
	int	len;
	int	i;

	len = len_string(c) + 1;
	i = 0;
	while (i <= 31)
	{
		if ((len >> i & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	send_string(pid_t pid, char *c)
{
	int	i;

	while (*c)
	{
		i = 0;
		while (i <= 7)
		{
			if ((*c >> i & 1) == 0)
				kill(pid, SIGUSR2);
			else if ((*c >> i & 1) == 1)
				kill(pid, SIGUSR1);
			usleep(50);
			i++;
		}
		c++;
	}
	while (i > 0)
	{
		kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}

void	send_binaries(pid_t pid, char *c)
{
	send_lenght(pid, c);
	send_string(pid, c);
}
