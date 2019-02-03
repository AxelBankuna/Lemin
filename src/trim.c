/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:55:13 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/16 15:40:29 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			deadends(struct s_room **head)
{
	struct s_room	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->end != 1 && temp->start != 1)
		{
			if (temp->nextroom2 == NULL)
			{
				breakconnect(temp);
				*head = removeroom(*head, temp);
				temp = *head;
			}
			else
				temp = temp->next;
		}
		else
			temp = temp->next;
	}
}

struct s_room	*removeroom(struct s_room *head, struct s_room *temp)
{
	struct s_room	*theprev;
	struct s_room	*thenext;

	if (head == temp)
	{
		head = head->next;
		free(temp);
	}
	else if (temp->next == NULL)
	{
		theprev = temp->prev;
		free(temp);
		theprev->next = NULL;
	}
	else
	{
		theprev = temp->prev;
		thenext = temp->next;
		theprev->next = thenext;
		thenext->prev = theprev;
		free(temp);
	}
	return (head);
}

void			breakconnect(struct s_room *temp)
{
	struct s_room	*connect;

	connect = temp->nextroom1;
	if (connect->nextroom1 == temp)
	{
		connect->nextroom1 = connect->nextroom2;
		connect->nextroom2 = NULL;
	}
	else if (connect->nextroom2 == temp)
		connect->nextroom2 = NULL;
	else if (connect->nextroom3 == temp)
		connect->nextroom3 = NULL;
	else if (connect->nextroom4 == temp)
		connect->nextroom4 = NULL;
}

int				backcheck(int ants_start, struct s_room *head)
{
	struct s_room	*temp;

	temp = head;
	while (temp->start != 1)
		temp = temp->next;
	if (temp->ants_at_start == ants_start)
		return (0);
	return (1);
}

int				movethem_trim(struct s_room *temp, int round)
{
	if (movecheck1(temp, round) && temp->nextroom1->start != 1)
	{
		movethem1(temp);
		return (1);
	}
	if (movecheck2(temp, round) && temp->nextroom2->start != 1)
	{
		movethem2(temp);
		return (1);
	}
	if (movecheck3(temp, round) && temp->nextroom3->start != 1)
	{
		movethem3(temp);
		return (1);
	}
	if (movecheck4(temp, round) && temp->nextroom4->start != 1)
	{
		movethem4(temp);
		return (1);
	}
	return (0);
}
