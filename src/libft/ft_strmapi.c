/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:16:49 by mbastard          #+#    #+#             */
/*   Updated: 2022/12/11 18:26:15 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*d;

	i = -1;
	if (!s || !f)
		return ((char *)s);
	d = ft_strdup(s);
	if (!d)
		return (NULL);
	while (s[++i])
		d[i] = f(i, s[i]);
	return (d);
}
