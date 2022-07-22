/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:32:59 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/22 10:13:24 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dst_checked(char *dst)
{
	int	i;

	i = 0;
	if (dst != NULL)
	{
		while (dst[i] && dst != NULL)
		{
			if (dst[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_free(char **src1, char **src2, int n)
{
	if (n == 1)
	{
		if (*src1)
			free(*src1);
		*src1 = NULL;
	}
	else if (n == 2)
	{
		if (*src1)
			free(*src1);
		if (*src2)
			free(*src2);
		*src1 = NULL;
		*src2 = NULL;
	}
}

char	*ft_read(char *dst, int fd)
{
	int		buffer_size;
	char	*buf;
	int		ret;

	buffer_size = 1;
	buf = ft_calloc((buffer_size + 1), sizeof(char));
	ret = 1;
	if (buf == NULL || buffer_size == 0)
		return (NULL);
	while (ret && dst_checked(dst) == 0)
	{
		ret = read(fd, buf, buffer_size);
		if (ret == -1)
		{
			ft_free(&buf, &dst, 1);
			return (NULL);
		}
		buf[ret] = '\0';
		dst = strjoin(dst, buf);
	}
	ft_free(&buf, &dst, 1);
	return (dst);
}
