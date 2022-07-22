/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:10:56 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 15:27:39 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	pid_t	pid_client;

	if (check_errors(argc, argv) == -1)
		return (0);
	signal(SIGUSR1, get_reception);
	pid_server = ft_atol(argv[1]);
	pid_client = getpid();
	send_binaries(pid_server, pid_client, argv[2]);
	while (1)
		usleep(1);
}
