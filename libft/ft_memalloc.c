/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:51:33 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/15 11:42:14 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;

	new_mem = malloc(size);
	if (!new_mem)
		return (NULL);
	ft_memset(new_mem, 0, size);
	return (new_mem);
}
