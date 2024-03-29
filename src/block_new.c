/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:45:37 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 15:39:41 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

t_block	*fuck_norm(size_t size, t_block *b_run, t_block *block_location)
{
	if (b_run && !b_run->next)
	{
		block_location = b_run->data + b_run->size;
	}
	if (!block_location)
		return (NULL);
	block_location->previous = b_run;
	block_location->next = (b_run) ? b_run->next : NULL;
	if (b_run)
		b_run->next = block_location;
	if (block_location->next)
		block_location->next->previous = block_location;
	block_location->data = block_location + 1;
	block_location->size = size;
	return (block_location);
}

t_block	*block_new(t_zone *zone, size_t size)
{
	t_block	*b_run;
	t_block	*block_location;

	block_location = NULL;
	b_run = zone->block_start;
	if (!b_run)
	{
		block_location = zone->data;
		zone->block_start = block_location;
	}
	while ((b_run && b_run->next) && !block_location)
	{
		if ((size_t)(((int64_t)b_run->next) - (int64_t)
		(b_run->data + ((b_run)->size - 1))) >= (size + BLOCK_META_SIZE))
		{
			block_location = b_run->data + b_run->size;
			break ;
		}
		b_run = b_run->next;
	}
	return (fuck_norm(size, b_run, block_location));
}
