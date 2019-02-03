/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/14 17:54:46 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

struct s_room	*createnode(char *x)
{
	struct s_room	*newnode;

	newnode = (struct s_room*)malloc(sizeof(struct s_room));
	newnode->roomnum = ft_strdup(x);
	free(newnode->roomnum);
	newnode->start = 0;
	newnode->end = 0;
	newnode->ant = -1;
	newnode->prev_room = ft_strdup("-1");
	newnode->backprev = ft_strdup("-1");
	newnode->round = 0;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->nextroom1 = NULL;
	newnode->nextroom2 = NULL;
	newnode->nextroom3 = NULL;
	newnode->nextroom4 = NULL;
	return (newnode);
}

struct s_room	*load_room(struct s_room *head, struct s_room *t,
		char *x, int stat)
{
	struct s_room	*newnode;

	load_room_1(&newnode, x);
	if (stat == 1)
	{
		newnode->start = 1;
		newnode->ants_at_start = allinfo.ants_start;
	}
	if (stat == 2)
		newnode->end = 1;
	newnode->next = NULL;
	t = head;
	if (head == NULL)
	{
		head = newnode;
		return (newnode);
	}
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = newnode;
		newnode->prev = t;
	}
	return (head);
}

int				isroom(char *line)
{
	char	**split;

	split = NULL;
	split = ft_strsplit(line, ' ');
	if (!ft_strcmp(split[0], line) || line[0] == '#')
		return (0);
	return (1);
}

int				isconnect(char *line)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return (0);
		i++;
	}
	split = ft_strsplit(line, '-');
	if (!ft_strcmp(split[0], line))
		return (0);
	return (1);
}

struct s_room	*read_in(struct s_room *head)
{
	char			*line;
	char			**split;
	struct s_room	*temp2;

	temp2 = NULL;
	split = NULL;
	get_next_line(0, &line);
	allinfo.ants_start = ft_atoi(line);
	allinfo.ants_end = 0;
	read_in_rooms(&head, line, split, temp2);
	return (head);
}
