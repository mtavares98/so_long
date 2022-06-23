/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:50:17 by mtavares          #+#    #+#             */
/*   Updated: 2022/03/04 18:02:47 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*scpy;
	int		len;

	len = ft_strlen(s1) + 1;
	scpy = (char *)malloc(len * sizeof(char));
	if (!scpy)
		return (NULL);
	ft_memmove(scpy, s1, len - 1);
	scpy[len - 1] = 0;
	return (scpy);
}
