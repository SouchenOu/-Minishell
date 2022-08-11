/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:52 by souchen           #+#    #+#             */
/*   Updated: 2022/06/22 11:53:00 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*s2;

	if (s == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	size = ft_strlen(s);
	if (!s2)
		return (NULL);
	i = 0;
	if (start < size)
	{
		while (i < len)
		{
			s2[i] = s[start];
			start++;
			i++;
		}
	}
	s2[i] = '\0';
	return (s2);
}
