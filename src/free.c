#include "../includes/malloc.h"

void ft_free(void *ptr){
	t_zone	*h_run;
	t_block	*b_run;

	h_run = s_base;
	while (h_run)
	{
		b_run = h_run->block_start;
		while (b_run){
			if (b_run->data == ptr){
				block_free(h_run, b_run);
				break;
			}
			b_run = b_run->next;
		}
		if (zone_free(h_run))
			break;
		h_run = h_run->next;

	}
}