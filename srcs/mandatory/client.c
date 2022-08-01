/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:10:56 by jsauvain          #+#    #+#             */
/*   Updated: 2022/08/01 13:55:03 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t	c_pid;
	
	if (check_errors(argc, argv) == -1 || argv[2][0] == '\0')
		return (0);
	var.g_pid = ft_atol(argv[1]);
	c_pid = getpid();
	var.string = argv[2];
	send_pid(c_pid);
	signal(SIGUSR1, send_string);
	signal(SIGUSR2, end_communication);
	return (0);
}
