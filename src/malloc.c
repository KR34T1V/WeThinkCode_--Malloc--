/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:46:05 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/16 18:19:55 by cterblan         ###   ########.fr       */
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

t_zone	*new_zone(t_zone **base, size_t size)
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
	ret->next = *base;
	if (*base)
	{
		ret->previous = (*base)->previous;
		(*base)->previous = ret;
	}
	*base = ret;
	return ret;
}

t_zone	*get_zone(t_zone **base, size_t size){
	t_zone	*run;
	run = *base;

	if (what_type(size) == LARGE)
		return new_zone(base, size);
	while (run){
		if (run->type == what_type(size))
		{
			t_block *runner2;
			runner2 = run->block_start;
			if (!runner2)
				return (run);
			while (runner2->next)
			{
				if ((unsigned int)((runner2->next->data) - (runner2->data + runner2->size - 1)) >= size)
					return (run);
				runner2 = runner2->next;
			}
			if ((unsigned int)((run->data + run->size - 1) - (runner2->data + runner2->size - 1)) >= size)
				return (run);
		}
		run = run->next;
	}
	return new_zone(base, size);
}

void	*allocate(t_zone *zone)
{
	if (zone)
		return NULL;
	return(NULL);
}

void    *ft_malloc(size_t size){
	static t_zone 	*s_base = NULL;
	t_zone			*current;

	if (size <= 0)
		return (0);

	//Assign new memory zone
	current = get_zone(&s_base, size);
	return allocate(current);
	return (0);
}