/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:18:22 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/23 23:18:37 by cterblan         ###   ########.fr       */
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
	if ((zone->block_start == block) && !block->next)
		zone->block_start = NULL;
}
