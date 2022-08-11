/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:52 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 15:45:27 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*test;
	int		j;

	j = 0;
	if (s1 == NULL)
	{
		return (NULL);
	}
	test = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (test == NULL)
	{
		return (NULL);
	}
	while (*s1 != '\0')
	{
		test[j] = *(s1++);
		j++;
	}
	while (*s2 != '\0')
	{
		test[j++] = *(s2++);
	}
	test[j] = '\0';
	return (test);
}