/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:20:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/20 09:06:10 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>

int		len_string(char *c);
int		ft_atoi(const char *nptr);
void	send_pid(pid_t pid_server, pid_t pid_client);
void	send_lenght(pid_t pid_server, char *c);
void	send_string(pid_t pid_server, char *c);
void	send_binaries(pid_t pid_server, pid_t pid_client, char *c);
void	get_reception(int sig);

#endif
