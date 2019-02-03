/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/14 17:58:39 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			read_in_rooms(struct s_room **head, char *line,
		char **split, struct s_room *temp2)
{
	struct s_room	*t;

	t = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp("##start", line))
		{
			get_next_line(0, &line);
			split = ft_strsplit(line, ' ');
			if (isroom(line))
				*head = load_room(*head, t, split[0], 1);
		}
		else if (!ft_strcmp("##end", line))
			read_in_rooms2(line, head, split, t);
		else if (isroom(line))
		{
			split = ft_strsplit(line, ' ');
			*head = load_room(*head, t, split[0], 0);
		}
		if (isconnect(line) == 1)
		{
			split = ft_strsplit(line, '-');
			*head = connect(head, split[0], split[1], temp2);
		}
	}
}

void			read_in_rooms2(char *line, struct s_room **head,
		char **split, struct s_room *t)
{
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	if (isroom(line))
		*head = load_room(*head, t, split[0], 2);
}

struct s_room	*connect(struct s_room **head, char *room1,
		char *room2, struct s_room *temp2)
{
	struct s_room	*temp1;

	temp1 = *head;
	temp2 = *head;
	while (ft_strcmp(temp1->roomnum, room1))
		temp1 = temp1->next;
	while (ft_strcmp(temp2->roomnum, room2))
		temp2 = temp2->next;
	if (!temp1->nextroom1)
		temp1->nextroom1 = temp2;
	else if (!temp1->nextroom2)
		temp1->nextroom2 = temp2;
	else if (!temp1->nextroom3)
		temp1->nextroom3 = temp2;
	else if (!temp1->nextroom4)
		temp1->nextroom4 = temp2;
	if (!temp2->nextroom1)
		temp2->nextroom1 = temp1;
	else if (!temp2->nextroom2)
		temp2->nextroom2 = temp1;
	else if (!temp2->nextroom3)
		temp2->nextroom3 = temp1;
	else if (!temp2->nextroom4)
		temp2->nextroom4 = temp1;
	return (*head);
}

void			load_room_1(struct s_room **newnode, char *x)
{
	*newnode = createnode(x);
	(*newnode)->roomnum = x;
}
