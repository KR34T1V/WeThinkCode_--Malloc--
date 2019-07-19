/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:50:55 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/19 15:51:14 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_zone	*zone_find(size_t size)
{
	t_zone	*h_run;
	t_block	*b_run;

	h_run = g_base;
	while (h_run)
	{
		if (h_run->type == zone_type(size))
		{
			b_run = h_run->block_start;
			if (!b_run)
				return (h_run);
			while (b_run->next)
			{
				if ((size_t)(((int64_t)b_run->next) - (int64_t)
				(b_run->data + (b_run->size - 1))) >= (size + BLOCK_META_SIZE))
					return (h_run);
				b_run = b_run->next;
			}
			if ((size_t)((h_run->data + (h_run->size) - 1) - (b_run->data +
			(b_run->size - 1))) >= (size + BLOCK_META_SIZE))
				return (h_run);
		}
		h_run = h_run->next;
	}
	return (zone_new(size));
}
