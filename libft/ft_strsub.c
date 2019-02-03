/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:47:08 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 13:47:55 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (s != NULL)
	{
		while (s[index])
			index++;
		if (s == NULL || index < start || index < (start + (unsigned int)len))
			return (NULL);
		if ((str = (char*)malloc(sizeof(*str) * (len + 1))) == NULL)
			return (NULL);
		index = 0;
		while (index < len)
		{
			str[index] = s[start + index];
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
