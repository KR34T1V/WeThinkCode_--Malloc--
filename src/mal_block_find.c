#include "../includes/malloc.h"

t_block_meta				*mal_block_find(size_t size)
{
	t_block_meta *current = g_base;
	while (current && !(current->free && current->size >= size))
	{
		current = current->next;
	}
	return current;
}