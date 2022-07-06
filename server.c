/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:06:03 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/05 16:11:34 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	pid_t	pid;
	int		i;
	int		nb;

	pid = getpid();
	i = 0;
	nb = 0;
	ft_printf("%d", pid);
	signal(SIGUSR1, &get_bin(SIGUSR1, &i, &nb));
	signal(SIGUSR2, &get_bin(SIGUSR2, &i, &nb));
	if (nb == 7)
	{
		i = 0;
		nb = 0;
	}
	while (1)
		usleep(1);;
}
