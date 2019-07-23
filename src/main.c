/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/23 23:19:16 by cterblan         ###   ########.fr       */
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
	
	ptr1 = ft_malloc(10);
	ptr2 = ft_malloc(117);
	ft_memset(ptr2, 42, 117);
	ptr3 = ft_malloc(129);
	ft_memset(ptr3, 42, 129);
	ptr4 = ft_malloc(10);
	show_alloc_mem();
	ft_realloc(ptr2, 20);
	show_alloc_mem();
	ft_free(ptr4);
	ft_free(ptr3);
	ft_free(ptr1);
    return (0);
}