/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backwards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/16 15:06:22 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

struct s_room		*backwards(struct s_room **head)
{
	struct s_room	*temp;

	temp = *head;
	while (temp && temp->end != 1)
		temp = temp->next;
	while (temp->ant == -1 || temp->end == 1)
	{
		if (temp->nextroom1 && temp->nextroom1->roomnum != temp->backprev)
			if (backwards_1(&temp))
				return (temp);
		if (temp->nextroom2 && temp->nextroom2->roomnum != temp->backprev)
			if (backwards_2(&temp))
				return (temp);
		if (temp->nextroom3 && temp->nextroom3->roomnum != temp->backprev)
			if (backwards_3(&temp))
				return (temp);
		if (temp->nextroom4 && temp->nextroom4->roomnum != temp->backprev)
			if (backwards_4(&temp))
				return (temp);
	}
	return (temp);
}

int					backwards_1(struct s_room **temp)
{
	(*temp)->nextroom1->backprev = (*temp)->roomnum;
	*temp = (*temp)->nextroom1;
	if ((*temp)->ant != -1)
		return (1);
	return (0);
}

int					backwards_2(struct s_room **temp)
{
	(*temp)->nextroom2->backprev = (*temp)->roomnum;
	*temp = (*temp)->nextroom2;
	if ((*temp)->ant != -1)
		return (1);
	return (0);
}

int					backwards_3(struct s_room **temp)
{
	(*temp)->nextroom3->backprev = (*temp)->roomnum;
	*temp = (*temp)->nextroom3;
	if ((*temp)->ant != -1)
		return (1);
	return (0);
}

int					backwards_4(struct s_room **temp)
{
	(*temp)->nextroom4->backprev = (*temp)->roomnum;
	*temp = (*temp)->nextroom4;
	if ((*temp)->ant != -1)
		return (1);
	return (0);
}
