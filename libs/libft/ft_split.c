/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:45:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/03/04 17:59:01 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_counter(char const *s, char c)
{
	int	i;
	int	counter_str;

	i = 0;
	counter_str = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter_str++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (counter_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*str;
	size_t	counter_str;

	if (s == NULL)
		return (NULL);
	counter_str = ft_str_counter(s, c);
	new = (char **)malloc(sizeof(char *) * (counter_str + 1));
	if (new == NULL)
		return (NULL);
	str = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (str != s)
				*(new ++) = ft_substr(str, 0, s - str);
			str = (char *)s + 1;
		}
		s++;
	}
	if (str != s)
		*(new ++) = ft_substr(str, 0, s - str);
	*new = 0;
	return (new - counter_str);
}
