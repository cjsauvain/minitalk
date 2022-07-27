/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:02:12 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/26 18:39:23 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include "libft.h"

int		ft_power(int nb, int power, int sig);
int		get_lenght(int sig);
int		get_string(int sig, char *str);
void	get_bin(int sig);

#endif
