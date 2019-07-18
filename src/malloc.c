/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:51:00 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/18 23:43:46 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE_MALLOC
#include "../includes/malloc.h"
#include "../includes/global.h"

//RENAME BACK TO MALLOC
void    *ft_malloc(size_t size){
	t_zone	*current;
	t_block	*new_block;

	if (size <= 0)
		return (NULL);
	current = zone_find(size);
	new_block = block_new(current, size);

	// printf("Block = %p, Data = %p, Size = %ld, Next = %p, Previous = %p", new_block, new_block->data, new_block->size, new_block->next, new_block->previous);
	// if (new_block->previous && new_block->previous->next)
	// 	printf("Previous->Next = %p\n", new_block->previous->next);
	// else
	// 	printf("FAILED\n");
	return (new_block->data);
}