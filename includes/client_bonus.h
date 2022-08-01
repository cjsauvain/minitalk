/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:20:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/08/01 15:59:18 by jsauvain         ###   ########.fr       */
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
void	end_communication(int sig);
void	send_pid(pid_t c_pid);
void	send_string(int sig);

#endif
