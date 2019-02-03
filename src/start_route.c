/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2018/09/26 18:50:38 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		start_route(struct s_room *head)
{
	struct s_room	*roomtemp;

	roomtemp = head;
	while (roomtemp->start != 1)
		roomtemp = roomtemp->next;
	if (roomtemp->nextroom1 && roomtemp->nextroom1->roomnum !=
			roomtemp->prev_room && roomtemp->ants_at_start &&
			roomtemp->nextroom1->ant == -1)
		start_route1(roomtemp);
	if (roomtemp->nextroom2 && roomtemp->nextroom2->roomnum
			!= roomtemp->prev_room && roomtemp->ants_at_start
			&& roomtemp->nextroom2->ant == -1)
		start_route2(roomtemp);
	if (roomtemp->nextroom3 && roomtemp->nextroom3->roomnum
			!= roomtemp->prev_room && roomtemp->ants_at_start
			&& roomtemp->nextroom2->ant == -1)
		start_route3(roomtemp);
	if (roomtemp->nextroom4 && roomtemp->nextroom4->roomnum
			!= roomtemp->prev_room && roomtemp->ants_at_start
			&& roomtemp->nextroom2->ant == -1)
		start_route4(roomtemp);
}

void		start_route1(struct s_room *roomtemp)
{
	roomtemp->nextroom1->prev_room = roomtemp->roomnum;
	roomtemp->nextroom1->ant = allinfo.ants_start - roomtemp->ants_at_start + 1;
	roomtemp->nextroom1->round++;
	roomtemp->ants_at_start--;
	theprint(roomtemp->nextroom1->ant, roomtemp->nextroom1->roomnum);
	if (roomtemp->nextroom1->end == 1)
		allinfo.ants_end++;
}

void		start_route2(struct s_room *roomtemp)
{
	roomtemp->nextroom2->prev_room = roomtemp->roomnum;
	roomtemp->nextroom2->ant = allinfo.ants_start - roomtemp->ants_at_start + 1;
	roomtemp->nextroom2->round++;
	roomtemp->ants_at_start--;
	theprint(roomtemp->nextroom2->ant, roomtemp->nextroom2->roomnum);
	if (roomtemp->nextroom2->end == 1)
		allinfo.ants_end++;
}

void		start_route3(struct s_room *roomtemp)
{
	roomtemp->nextroom3->prev_room = roomtemp->roomnum;
	roomtemp->nextroom3->ant = allinfo.ants_start - roomtemp->ants_at_start + 1;
	roomtemp->nextroom3->round++;
	roomtemp->ants_at_start--;
	theprint(roomtemp->nextroom3->ant, roomtemp->nextroom3->roomnum);
	if (roomtemp->nextroom3->end == 1)
		allinfo.ants_end++;
}

void		start_route4(struct s_room *roomtemp)
{
	roomtemp->nextroom4->prev_room = roomtemp->roomnum;
	roomtemp->nextroom4->ant = allinfo.ants_start - roomtemp->ants_at_start + 1;
	roomtemp->nextroom4->round++;
	roomtemp->ants_at_start--;
	theprint(roomtemp->nextroom4->ant, roomtemp->nextroom4->roomnum);
	if (roomtemp->nextroom4->end == 1)
		allinfo.ants_end++;
}
