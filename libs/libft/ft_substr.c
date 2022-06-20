/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:58:55 by mtavares          #+#    #+#             */
/*   Updated: 2022/03/07 18:02:04 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
