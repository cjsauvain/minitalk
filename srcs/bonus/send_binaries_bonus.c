/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_binaries_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:41 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/27 16:06:49 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	send_pid(pid_t pid_server, pid_t pid_client)
{
	int	j;

	j = 0;
	while (j <= 31)
	{
		if ((pid_client >> j & 1) == 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(50);
		j++;
	}
}

void	send_lenght(pid_t pid_server, char *c)
{
	int	len;
	int	i;

	len = ft_strlen(c) + 1;
	i = 0;
	while (i <= 31)
	{
		if ((len >> i & 1) == 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	send_string(pid_t pid_server, char *c)
{
	int	i;

	while (*c)
	{
		i = 0;
		while (i <= 7)
		{
			if ((*c >> i & 1) == 0)
				kill(pid_server, SIGUSR2);
			else if ((*c >> i & 1) == 1)
				kill(pid_server, SIGUSR1);
			usleep(50);
			i++;
		}
		c++;
	}
	i = 0;
	while (i <= 7)
	{
		kill(pid_server, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	send_binaries(pid_t pid_server, pid_t pid_client, char *c)
{
	send_pid(pid_server, pid_client);
	send_lenght(pid_server, c);
	send_string(pid_server, c);
}
