/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:10:56 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/20 10:21:53 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	pid_t	pid_client;

	(void)argc;
	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	send_binaries(pid_server, pid_client, argv[2]);
	signal(SIGUSR1, get_reception);
}
