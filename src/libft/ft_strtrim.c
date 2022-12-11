/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:23:42 by mbastard          #+#    #+#             */
/*   Updated: 2022/12/11 18:26:34 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	start;
	unsigned long	end;
	char			*s2;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (start == ft_strlen(s1))
		end = 0;
	while (ft_strchr(set, s1[end]) && end)
		end--;
	if (end)
		end = ft_strlen(s1) - end - 1;
	s2 = (char *)ft_calloc(ft_strlen(s1) - start - end + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[start], ft_strlen(s1) - start - end + 1);
	return ((char *)s2);
}
