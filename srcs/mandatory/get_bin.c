/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/08/01 13:57:33 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_power(int nb, int power, int sig)
{
	int	n;

	n = nb;
	if (sig == SIGUSR2)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= n;
		power--;
	}
	return (nb);
}

int	get_client_pid(int sig)
{
	static int	i = 0;
	static int	nb = 0;
	int			c_pid;

	if (nb <= 30)
	{
		i += ft_power(2, nb, sig);
		nb++;
		return (0);
	}
	i += ft_power(2, nb, sig);
	c_pid = i;
	i = 0;
	nb = 0;
	return (c_pid);
}

void	get_bin(int sig)
{
	static int	nb = 0;
	static int	c_pid = 0;
	static char	*str = NULL;
	static char	tmp = 0;;

	if (c_pid == 0)
		c_pid = get_client_pid(sig);
	else
	{
		tmp += ft_power(2, nb, sig);
		nb++;
		if (nb == 8)
		{
			if (tmp == 0)
			{
				kill(c_pid, SIGUSR2);
				ft_printf("%s\n", str);
				free(str);
				str = NULL;
				tmp = 0;
				nb = 0;
				return ;
			}
			str = ft_strjoin(str, tmp);
			tmp = 0;
			nb = 0;
		}
	}
	kill(c_pid, SIGUSR1);
}
