/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:10:56 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 15:48:17 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	
	if (check_errors(argc, argv) == -1 || argv[2][0] == '\0')
		return (0);
	else
	{
		pid = ft_atol(argv[1]);
		send_binaries(pid, argv[2]);
	}
	return (0);
}
