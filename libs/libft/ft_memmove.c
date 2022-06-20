/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:17:53 by mtavares          #+#    #+#             */
/*   Updated: 2022/03/04 17:52:56 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!d && !s)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dest);
}
