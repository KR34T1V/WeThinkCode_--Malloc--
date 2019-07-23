/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:21:17 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/23 23:19:46 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

int	zone_free(t_zone *zone)
{
	t_zone	*prev;

	prev = zone->previous;
	if (!zone->block_start)
	{
		if (zone->previous)
			zone->previous->next = zone->next;
		if (zone->next)
			zone->next->previous = prev;
		if (g_base == zone)
			g_base = zone->next;
		munmap(zone, (zone->size + HEAP_META_SIZE));
		return (1);
	}
	return (0);
}
