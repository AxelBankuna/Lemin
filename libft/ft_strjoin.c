/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:44:01 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 16:07:22 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joining(int index, int s2_i, char const *s1, char const *s2)
{
	char	*str;

	str = NULL;
	if ((str = (char*)malloc(sizeof(*str) * (index))) == NULL)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	s2_i = 0;
	while (s2[s2_i])
	{
		str[index] = s2[s2_i];
		index++;
		s2_i++;
	}
	str[index] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		s2_i;

	s2_i = 0;
	index = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[index])
		index++;
	while (s2[s2_i])
	{
		index++;
		s2_i++;
	}
	if (index)
		index--;
	return (ft_joining(index, s2_i, s1, s2));
}
