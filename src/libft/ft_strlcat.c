/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:51 by mbastard          #+#    #+#             */
/*   Updated: 2022/12/11 18:25:29 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (dst[i] && dstsize - i)
		i++;
	if (dstsize - i)
	{
		while (src[j] && (dstsize - i - 1))
			dst[i++] = src[j++];
		dst[i] = 0;
	}
	return (i - j + ft_strlen(src));
}
