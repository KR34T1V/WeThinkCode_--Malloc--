/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:45:37 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/19 16:23:45 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	fuck_norm(t_zone *z, size_t s, t_block *b_run, t_block **block_loc)
{
	if (!b_run)
	{
		*block_loc = z->data;
		z->block_start = *block_loc;
	}
	while ((b_run && b_run->next) && !*block_loc)
	{
		if ((size_t)(((int64_t)b_run->next) - (int64_t)
		(b_run->data + ((b_run)->size - 1))) >= (s + BLOCK_META_SIZE))
		{
			*block_loc = b_run->data + b_run->size;
			break ;
		}
		b_run = b_run->next;
	}
}

t_block		*block_new(t_zone *zone, size_t size)
{
	t_block	*b_run;
	t_block	*block_location;

	block_location = NULL;
	b_run = (zone->block_start);
	fuck_norm(zone, size, b_run, &block_location);
	if (b_run && !b_run->next)
		block_location = b_run->data + b_run->size;
	if (!block_location)
		return (NULL);
	block_location->previous = b_run;
	block_location->next = b_run ? b_run->next : NULL;
	if (b_run)
		b_run->next = block_location;
	if (block_location->next)
		block_location->next->previous = block_location;
	block_location->data = block_location + BLOCK_META_SIZE;
	block_location->size = size;
	return (block_location);
}
