/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reception_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:13:38 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 09:22:17 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	get_reception(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message received !\n");
		exit(1);
	}
}
