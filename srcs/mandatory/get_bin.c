/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/27 16:45:34 by jsauvain         ###   ########.fr       */
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

int	get_lenght(int sig)
{
	static int	i = 0;
	static int	nb = 0;
	int			len;

	if (nb <= 30)
	{
		i += ft_power(2, nb, sig);
		nb++;
		return (0);
	}
	len = i;
	i = 0;
	nb = 0;
	return (len);
}

int	get_string(int sig, char *str)
{
	static int	i = 0;
	static int	nb = 0;

	str[i] += ft_power(2, nb, sig);
	nb++;
	if (nb == 8)
	{
		if (str[i])
		{
			i++;
			nb = 0;
		}
		else if (str[i] == 0)
		{
			ft_printf("%s\n", str);
			i = 0;
			nb = 0;
			free(str);
			str = NULL;
			return (1);
		}
	}
	return (0);
}

void	get_bin(int sig)
{
	static char	*str = NULL;
	static int	len = 0;

	if (len == 0)
		len = get_lenght(sig);
	else
	{
		if (len != -1)
		{
			ft_printf("%d\n", len);
			str = ft_calloc(len, sizeof(char));
			if (str == NULL)
			{
				ft_printf("Error : Malloc could not be done.\n");
				exit(1);
			}
			len = -1;
		}
		if (get_string(sig, str) == 1)
			len = 0;
	}
}
