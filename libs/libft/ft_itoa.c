/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:07:29 by mtavares          #+#    #+#             */
/*   Updated: 2022/03/06 19:39:33 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numdig(int n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_numdig(n / 10));
}

char	*ft_itoa(int n)
{
	char	*num;
	int		num_dig;
	int		i;
	int		signal;

	signal = n;
	num_dig = ft_numdig(n) + 1 + (n < 0);
	num = (char *)malloc(sizeof(char) * num_dig);
	if (!num)
		return (NULL);
	num[num_dig - 1] = '\0';
	i = num_dig - 2;
	while (i > -1)
	{
		num[i] = ((n % 10) * ((n > 0) - (n < 0))) + 48;
		n /= 10;
		i--;
	}
	if (signal < 0)
		num[0] = '-';
	return (num);
}
