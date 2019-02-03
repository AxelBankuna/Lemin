/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 15:41:18 by abukasa           #+#    #+#             */
/*   Updated: 2017/07/22 16:20:58 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	index = 0;
	str = (char*)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (index <= size)
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}
