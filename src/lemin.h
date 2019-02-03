/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/16 15:37:57 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct				s_room
{
	char			*roomnum;
	int				start;
	int				end;
	int				ant;
	int				ants_at_start;
	char			*prev_room;
	char			*backprev;
	int				round;
	struct s_room	*next;
	struct s_room	*prev;
	struct s_room	*nextroom1;
	struct s_room	*nextroom2;
	struct s_room	*nextroom3;
	struct s_room	*nextroom4;
}					*head;

struct				s_info
{
	int				ants_start;
	int				ants_end;
}					allinfo;

struct				s_route
{
	int				room;
	struct s_route	*next;
}					*route_head;

struct				s_routes
{
	struct s_route	*theroutes;
	int				route_len;
	struct s_routes	*next;
}					*routes_head;

struct s_room		*createnode(char *x);
struct s_room		*load_room(struct s_room *head, struct s_room *t,
		char *x, int stat);
void				load_room_1(struct s_room **newnode, char *x);
int					isroom(char *line);
int					isconnect(char *line);
struct s_room		*read_in(struct s_room *head);
void				read_in_rooms(struct s_room **head, char *line,
		char **split, struct s_room *temp2);
void				read_in_rooms2(char *line, struct s_room **head,
		char **split, struct s_room *t);
struct s_room		*connect(struct s_room **head, char *room1,
		char *room2, struct s_room *temp2);
void				printrooms(struct s_room *head);
void				start_route(struct s_room *head);
void				start_route1(struct s_room *roomtemp);
void				start_route2(struct s_room *roomtemp);
void				start_route3(struct s_room *roomtemp);
void				start_route4(struct s_room *roomtemp);
void				movethem(struct s_room **head, int round);
void				movethem1(struct s_room *temp);
void				movethem2(struct s_room *temp);
void				movethem3(struct s_room *temp);
void				movethem4(struct s_room *temp);
int					movecheck1(struct s_room *temp, int round);
int					movecheck2(struct s_room *temp, int round);
int					movecheck3(struct s_room *temp, int round);
int					movecheck4(struct s_room *temp, int round);
void				allmoves(struct s_room *head);
struct s_room		*roundup(struct s_room *head, struct s_room *temp,
		struct s_room *nextroom, int round);
struct s_room		*backwards(struct s_room **head);
int					backwards_1(struct s_room **temp);
int					backwards_2(struct s_room **temp);
int					backwards_3(struct s_room **temp);
int					backwards_4(struct s_room **temp);
void				deadends(struct s_room **head);
struct s_room		*removeroom(struct s_room *head, struct s_room *temp);
void				breakconnect(struct s_room *temp);
void				theprint(int ant, char *room);
int					backcheck(int ants_start, struct s_room *head);
void				free_s_room(struct s_room **head);
int					movethem_trim(struct s_room *temp, int round);
#endif
