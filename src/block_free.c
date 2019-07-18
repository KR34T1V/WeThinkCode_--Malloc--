#include "../includes/malloc.h"

void	block_free(t_zone *zone, t_block *block){
	t_block *ptr;

	ptr = block->next;
	if (block->next){
		block->next->previous = block->previous;
	}
	if (block->previous){
		block->previous->next = ptr;
	}
	if ((zone->block_start == block) && !block->next){
		zone->block_start = NULL;
	}
}