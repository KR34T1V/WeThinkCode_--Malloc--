/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 17:02:42 by cterblan         ###   ########.fr       */
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
	show_alloc_mem();
	ft_putendl("===================================================");
	i = 0;
	while (i < 102){
		ptr1[i] = realloc(ptr1[i], 128);
		printf("S |%d|\n", i);
		i++;
	}
	show_alloc_mem();
	ft_putendl("===================================================");
	i = 0;
	while (i < 102){
		ptr1[i] = realloc(ptr1[i], 256);
		printf("L |%d|\n", i);
		i++;
	}
	show_alloc_mem();
	ft_putendl("===================================================");
	i = 0;
	while (i < 102){
		free(ptr1[i]);
		printf("F |%d|\n", i);
		i++;
	}
	show_alloc_mem();
    return (0);
}