/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:02:12 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 10:52:55 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include "libft.h"

int		power(int nb, int power, int sig);
int		get_binaries(int sig);
int		get_string(int sig, char *str);
void	get_bin(int sig);
void	send_message(int pid);
void	send_reception(int sig);

#endif
