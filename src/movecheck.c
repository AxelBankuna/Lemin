/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:46:00 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/15 18:33:34 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		movecheck1(struct s_room *temp, int round)
{
	if (temp->nextroom1 && temp->nextroom1->roomnum != temp->prev_room
		&& temp->end != 1 && temp->round < round &&
		(temp->nextroom1->ant == -1 || temp->nextroom1->end == 1))
		return (1);
	return (0);
}

int		movecheck2(struct s_room *temp, int round)
{
	if (temp->nextroom2 && temp->nextroom2->roomnum != temp->prev_room
		&& temp->end != 1 && temp->round < round &&
		(temp->nextroom2->ant == -1 || temp->nextroom2->end == 1))
		return (1);
	return (0);
}

int		movecheck3(struct s_room *temp, int round)
{
	if (temp->nextroom3 && temp->nextroom3->roomnum != temp->prev_room
		&& temp->end != 1 && temp->round < round &&
		(temp->nextroom3->ant == -1 || temp->nextroom3->end == 1))
		return (1);
	return (0);
}

int		movecheck4(struct s_room *temp, int round)
{
	if (temp->nextroom4 && temp->nextroom4->roomnum != temp->prev_room
		&& temp->end != 1 && temp->round < round &&
		(temp->nextroom4->ant == -1 || temp->nextroom4->end == 1))
		return (1);
	return (0);
}
