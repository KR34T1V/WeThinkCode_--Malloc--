/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 11:44:10 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

int main (){
	unsigned long zone_size = getpagesize()*15;
	void *ptr1;
	void *ptr2;
	void *ptr3;
	void *ptr4;
	t_zone *h_run;
	t_block *b_run;
	
	ptr1 = malloc(10);
	ptr2 = malloc(117);
	ptr3 = malloc(129);
	ptr4 = malloc(10);
	show_alloc_mem();
	realloc(ptr2, 20);
	show_alloc_mem();
	free(ptr4);
	free(ptr3);
	free(ptr1);
    return (0);
}