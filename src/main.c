/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 16:24:33 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

int main (){
	unsigned long zone_size = getpagesize()*15;
	void *ptr1[200];
	int i = 0;

	t_zone *h_run;
	t_block *b_run;
	
	//101 TINY ALLOCATIONS
	while (i < 102){
		ptr1[i] = malloc(32);
		printf("%d\n", i);
		i++;
	}
	for (int i = 0; i < 50; i++)
		free(ptr1[i]);
	
	i = 0;
	while (i < 102){
		ptr1[i] = malloc(32);
		printf("%d\n", i);
		i++;
	}
	//101 SMALL ALLOCATIONS
	i = 0;
	while (i < 102){
		void *ptr2 = malloc(128);
		printf("%d\n", i);
		i++;
	}
	show_alloc_mem();
	free(ptr1);
    return (0);
}