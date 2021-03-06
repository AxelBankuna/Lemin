/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 12:59:43 by abukasa           #+#    #+#             */
/*   Updated: 2017/06/11 15:50:30 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_len(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char		*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		s1_len;
	int		index;

	s1_len = ft_str_len(s1);
	index = ft_str_len((char*)s2);
	if (s1_len == 0 && index > 0)
	{
		index = -1;
		while (s2[++index])
			s1[index] = s2[index];
		s1[index] = '\0';
		return (s1);
	}
	if (s1_len > 0 && index == 0)
		return (s1);
	index = 0;
	while (s2[index])
	{
		s1[s1_len] = s2[index];
		s1_len++;
		index++;
	}
	s1[s1_len] = '\0';
	return (s1);
}
