/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:41 by jsauvain          #+#    #+#             */
/*   Updated: 2022/08/01 14:00:06 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	end_communication(int sig)
{
	(void)sig;
	exit(1);	
}

void	send_pid(pid_t c_pid)
{
	int	i;

	i = 0;
	while (i <= 31)
	{
		if ((c_pid >> i & 1) == 1)
			kill(var.g_pid, SIGUSR1);
		else
			kill(var.g_pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	send_string(int sig)
{
	static int	i = 0;

	if (*var.string == 0)
		sig = SIGUSR2;
	else
	{
		if ((*var.string >> i & 1) == 0)
			sig = SIGUSR2;
		else
			sig = SIGUSR1;
	}
	i++;
	if (i == 8 && *var.string)
	{
		i = 0;
		var.string++;
	}
	kill(var.g_pid, sig);
}
