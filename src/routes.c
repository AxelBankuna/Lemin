/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/16 14:32:03 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			allmoves(struct s_room *head)
{
	int				round;
	struct s_room	*temp;

	round = 0;
	while (allinfo.ants_end < allinfo.ants_start)
	{
		temp = head;
		movethem(&head, round);
		start_route(head);
		while (temp)
		{
			temp->round = round;
			temp = temp->next;
		}
		round++;
		write(1, "\n", 1);
	}
}

struct s_room	*roundup(struct s_room *head, struct s_room *temp,
		struct s_room *nextroom, int round)
{
	temp->round = round;
	nextroom->round = round;
	return (head);
}
