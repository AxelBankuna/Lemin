/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/16 15:13:30 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/lemin.h"

int		main(void)
{
	head = NULL;
	head = read_in(head);
	deadends(&head);
	allmoves(head);
	return (0);
}
