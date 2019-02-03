/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:47:45 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 15:21:43 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	cmp_char;

	cmp_char = (char)c;
	index = 0;
	while (s[index] != cmp_char && s[index])
		index++;
	if (s[index] == cmp_char)
		return ((char*)&s[index]);
	return (NULL);
}
