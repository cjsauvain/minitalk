/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:06:03 by jsauvain          #+#    #+#             */
/*   Updated: 2022/08/01 15:26:17 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, get_bin);
	signal(SIGUSR2, get_bin);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		usleep(1);
}
