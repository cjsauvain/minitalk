/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:17:57 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 15:51:27 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
		{
			ft_printf("Error : Check your pid.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_argc(int argc)
{
	if (argc < 3)
	{
		ft_printf("Error : Missing arguments.\n");
		return (-1);
	}
	else if (argc > 3)
	{
		ft_printf("Error : Too much arguments.\n");
		return (-1);
	}
	return (0);
}

int	check_argv(char **argv)
{
	char	*str;

	if (!argv[2])
	{
		ft_printf("Error : NULL string.\n");
		return (-1);
	}
	else if (check_pid(argv[1]) == -1)
		return (-1);
	str = ft_itoa(ft_atol(argv[1]));
	if (ft_atol(argv[1]) <= 1
		|| ft_strncmp(str, argv[1], ft_strlen(argv[1])))
	{
		ft_printf("Error : Check your pid.\n");
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int	check_errors(int argc, char **argv)
{
	if (check_argc(argc) == -1)
		return (-1);
	else if (check_argv(argv) == -1)
		return (-1);
	return (0);
}

