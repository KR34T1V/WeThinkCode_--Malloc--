/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:18:22 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 17:02:49 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

void	block_free(t_zone *zone, t_block *block)
{
	t_block *ptr;

	ptr = block->next;
	if (block->next)
		block->next->previous = block->previous;
	if (block->previous)
		block->previous->next = ptr;
	else
		zone->block_start = ptr;
}
