/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:54:18 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/17 14:39:34 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"


t_zone	*zone_new(size_t size){
	t_zone	*new_zone;
	size_t	length;
	t_type	type;

	type = zone_type(size);
	if (type == LARGE)
		length = FIT_ZONE(size + HEAP_META_SIZE + BLOCK_META_SIZE);
	else if (type == SMALL)
		length = SMALL_ZONE;
	else
		length = TINY_ZONE;
	if ((new_zone = (t_zone *)mmap(0, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED)
		return (NULL);
	new_zone->type = type;
	new_zone->size = length - HEAP_META_SIZE;
	new_zone->data = new_zone + HEAP_META_SIZE;
	new_zone->block_start = NULL;
	new_zone->next = s_base;
	new_zone->previous = NULL;
	if (s_base){
		s_base->previous = new_zone;
	}
	s_base = new_zone;
	return (new_zone);
}