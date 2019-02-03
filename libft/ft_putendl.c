/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:16:20 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/16 18:09:20 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		index;

	index = 0;
	if (!s)
		write(1, "\n", 1);
	else
	{
		while (s[index])
		{
			write(1, &s[index], 1);
			index++;
		}
		write(1, "\n", 1);
	}
}