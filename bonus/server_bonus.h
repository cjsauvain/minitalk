/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:02:12 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/20 09:02:02 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <signal.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *s);
void	*ft_calloc(int nmemb);
int		power(int nb, int power, int sig);
int		get_binaries(int sig);
int		get_string(int sig, char *str);
void	get_bin(int sig);
char	*copy(char *str);
void	send_message(int pid);
void	send_reception(int sig);

#endif
