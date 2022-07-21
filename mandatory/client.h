/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:20:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/14 16:42:14 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>

int		len_string(char *c);
int		ft_atoi(const char *nptr);
void	send_lenght(pid_t pid, char *c);
void	send_string(pid_t pid, char *c);
void	send_binaries(pid_t pid, char *c);

#endif
