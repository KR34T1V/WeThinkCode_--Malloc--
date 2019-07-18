#include "../includes/malloc.h"
char	*determine_size(t_type type){
	if (type == TINY)
		return("TINY");
	else if (type == SMALL)
		return("SMALL");
	else
		return("LARGE");
}

void	show_alloc_mem()
{
	t_zone	*h_run;
	t_block	*b_run;
	size_t	total;

	total = 0;
	h_run = s_base;
	while(h_run)
	{
		printf("%s : %p\n", determine_size(h_run->type), h_run->data);
		b_run = h_run->block_start;
		while(b_run)
		{
			printf("%p - %p : %ld bytes\n", b_run->data, (b_run->data + b_run->size -1), b_run->size);
			total += b_run->size;
			b_run = b_run->next;
		}
		h_run = h_run->next;
	}
	
	printf("Total : %ld bytes\n", total);
}