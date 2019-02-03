/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:24:59 by abukasa           #+#    #+#             */
/*   Updated: 2017/06/09 21:02:16 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = s1[len];
		len--;
	}
	return (str);
}
