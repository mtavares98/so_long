/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:56:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/02/25 16:38:01 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c > 8 && c < 14) || c == 32);
}

int	ft_atoi(const char *str)
{
	int			s;
	long long	n;

	s = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = n * 10 + s * (*str - '0');
		str++;
		if (n > 2147483647)
			return (-1);
		if (n < -2147483648)
			return (0);
	}
	return (n);
}
