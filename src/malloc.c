/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:46:05 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/17 12:54:08 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_type	what_type(size_t size){
	if(size <= TINY_SIZE){
		return (TINY);
	} else if (size <= SMALL_SIZE){
		return (SMALL);
	} else {
		return (LARGE);
	}
}

t_zone	*new_zone(size_t size)
{
	t_zone *ret;
	t_type type = what_type(size);
	size_t length;

	if (type == LARGE)
		length = FIT_ZONE(size + HEAP_META_SIZE + BLOCK_META_SIZE);
	else if (type == SMALL)
		length = SMALL_ZONE;
	else
		length = TINY_ZONE;
	if ((ret = (t_zone *)mmap(0, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED)
		return (NULL);
	ret->type = type;
	ret->size = length - BLOCK_META_SIZE;
	ret->data = ret + BLOCK_META_SIZE;
	ret->block_start = NULL;
	ret->next = s_base;
	if (s_base)
	{
		ret->previous = s_base->previous;
		s_base->previous = ret;
	}
	s_base = ret;
	return ret;
}

t_zone	*get_zone(size_t size){
	t_zone	*run;
	t_block *b_run;
	run = s_base;

	if (what_type(size) == LARGE)
		return new_zone(size);
	while (run){
		if (run->type == what_type(size))
		{
			b_run = run->block_start;
			if (!b_run)
				return (run);
			while (b_run->next)
			{
				if ((unsigned int)((b_run->next->data) - (b_run->data + b_run->size - 1)) >= size)
					return (run);
				b_run = b_run->next;
			}
			if ((unsigned int)((run->data + run->size - 1) - (b_run->data + b_run->size - 1)) >= size)
				return (run);
		}
		run = run->next;
	}
	return new_zone(size);
}

void	*allocate_block(t_zone *zone, size_t size)
{
	t_block			*b_run;

	if (zone && size){
		b_run = zone->block_start;
		while (b_run){

		}

	}
	return(NULL);
}

void    *ft_malloc(size_t size){
	t_zone			*current;

	if (size <= 0)
		return (0);

	//Assign new memory zone
	current = get_zone(size);
	printf("%p:\n\t%p\n\t%p\n\t%d\n\t%lu\n",
		current,
		current->next,
		current->data,
		current->type,
		current->size
	);
	return allocate_block(current, size);
	return (0);
}