/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:52 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 15:45:54 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	step1(const char *str, int Del)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] && str[i] != Del)
	{
		len++;
		i++;
	}
	return (len);
}

static int	step2(const char *str, int Del)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != Del && (str[i + 1] == Del || !str[i + 1]))
			len++;
		i++;
	}
	return (len);
}

void	free_table(char **tab, int i)
{
	int	j;

	j = 0;
	while (tab[i] == NULL)
	{
		while (j <= i)
		{
			free(tab[j]);
			j++;
		}
		free(tab);
	}
}

static void	*step3(char const *str, char **tab, int stepx, int Del)
{
	int	stepy;
	int	x;
	int	y;

	y = 0;
	while (y < stepx)
	{
		while (*str == Del)
			str++;
		stepy = step1(str, Del);
		x = 0;
		tab[y] = (char *)malloc(sizeof(char) * (stepy + 1));
		if (!tab[y])
			free_table(tab, y);
		while (x < stepy)
		{
			tab[y][x++] = *str;
			str++;
		}
		tab[y][x] = '\0';
		y++;
	}
	return ((void *) 1);
}

char	**ft_split(char const *str, char Del)
{
	int		size;
	char	**tab;
	void	*resu;

	if (!str)
	{
		return (NULL);
	}
	size = step2(str, Del);
	tab = (char **)malloc (sizeof(char *) * (size + 1));
	if (tab == NULL)
	{
		return (NULL);
	}
	tab[size] = 0;
	resu = step3(str, tab, size, Del);
	return (tab);
}