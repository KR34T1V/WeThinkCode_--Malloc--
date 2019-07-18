/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/19 00:08:44 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int main (){
	unsigned long zone_size = getpagesize()*15;
	void *ptr1;
	void *ptr2;
	void *ptr3;
	void *ptr4;
	t_zone *h_run;
	t_block *b_run;
	
	// printf("HEAP MSize = %ld\nBlock MSize = %ld\nPage size: %u\n", HEAP_META_SIZE, BLOCK_META_SIZE, ZONE_SIZE);
	ptr1 = ft_malloc(10);
	ptr2 = ft_malloc(10);
	ptr3 = ft_malloc(10);
	ptr4 = ft_malloc(10);

	show_alloc_mem();
	ft_free(ptr4);
	ft_free(ptr2);
	ft_free(ptr3);
	ft_free(ptr1);
	// h_run = s_base;
	// while(h_run){
	// 	b_run = h_run->block_start;
	// 	while(b_run){
	// 		printf("Data = %p\n", b_run->data);
	// 		b_run = b_run->next;
	// 	}
	// 	h_run = h_run->next;
	// }
    return (0);
}