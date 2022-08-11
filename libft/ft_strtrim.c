/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:52 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 15:45:01 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrimstep1(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (set[j] != '\0' && s1[i] != '\0')
	{
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return ((char *)&s1[i]);
}

static int	ft_strtrimstep2(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s1) - 1;
	while (i > 0 && set[j] != '\0')
	{
		if (set[j] == s1[i])
		{
			i--;
			j = 0;
		}
		else
		{
			j++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		cmp;

	cmp = 0;
	if (!s1)
	{
		return (NULL);
	}
	s1 = ft_strtrimstep1(s1, set);
	if (s1[0] == '\0')
	{
		tab = (char *)malloc(1);
		tab[0] = '\0';
		return (tab);
	}
	tab = (char *)malloc(sizeof(char) * ft_strtrimstep2(s1, set) + 2);
	if (tab == NULL)
		return (NULL);
	while (cmp <= ft_strtrimstep2(s1, set))
	{
		tab[cmp] = s1[cmp];
		cmp++;
	}
	tab[cmp] = '\0';
	return (tab);
}