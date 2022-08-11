/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:42 by souchen           #+#    #+#             */
/*   Updated: 2022/06/22 11:35:43 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int					i;
	int					r;
	long long			result;

	i = 0;
	r = 1;
	result = 0;
	while ((str[i] == '\n' || str[i] == '\r' || str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f') && str[i])
		i++;
	if (str[i] == '-')
		r = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result < 0 && r == -1)
			return (0);
		if (result < 0 && r == 1)
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (r * result);
}

long long	my_atoi(const char *str)
{
	int					i;
	int					r;
	long long			result;

	i = 0;
	r = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result < 0)
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (r * result);
}
