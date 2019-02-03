/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movethem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/16 15:36:40 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		movethem(struct s_room **head, int round)
{
	struct s_room	*temp;

	temp = *head;
	while (temp && allinfo.ants_start != allinfo.ants_end)
	{
		if (!temp)
			return ;
		if (backcheck(allinfo.ants_start, *head))
			temp = backwards(head);
		if (!temp)
			return ;
		if (movethem_trim(temp, round))
			return ;
		temp = temp->next;
	}
}

void		movethem1(struct s_room *temp)
{
	temp->nextroom1->prev_room = temp->roomnum;
	temp->nextroom1->ant = temp->ant;
	temp->ant = -1;
	temp->nextroom1->round++;
	temp->round++;
	theprint(temp->nextroom1->ant, temp->nextroom1->roomnum);
	if (temp->nextroom1->end == 1)
		allinfo.ants_end++;
}

void		movethem2(struct s_room *temp)
{
	temp->nextroom2->prev_room = temp->roomnum;
	temp->nextroom2->ant = temp->ant;
	temp->ant = -1;
	temp->nextroom2->round++;
	temp->round++;
	theprint(temp->nextroom2->ant, temp->nextroom2->roomnum);
	if (temp->nextroom2->end == 1)
		allinfo.ants_end++;
}

void		movethem3(struct s_room *temp)
{
	temp->nextroom3->prev_room = temp->roomnum;
	temp->nextroom3->ant = temp->ant;
	temp->ant = -1;
	temp->nextroom3->round++;
	temp->round++;
	theprint(temp->nextroom3->ant, temp->nextroom3->roomnum);
	if (temp->nextroom3->end == 1)
		allinfo.ants_end++;
}

void		movethem4(struct s_room *temp)
{
	temp->nextroom4->prev_room = temp->roomnum;
	temp->nextroom4->ant = temp->ant;
	temp->ant = -1;
	temp->nextroom4->round++;
	temp->round++;
	theprint(temp->nextroom4->ant, temp->nextroom4->roomnum);
	if (temp->nextroom4->end == 1)
		allinfo.ants_end++;
}
