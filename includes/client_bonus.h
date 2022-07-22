/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:20:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 15:41:10 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include "libft.h"

int		check_pid(char *str);
int		check_argc(int argc);
int		check_argv(char **argv);
int		check_errors(int argc, char **argv);
void	send_pid(pid_t pid_server, pid_t pid_client);
void	send_lenght(pid_t pid_server, char *c);
void	send_string(pid_t pid_server, char *c);
void	send_binaries(pid_t pid_server, pid_t pid_client, char *c);
void	get_reception(int sig);

#endif
