/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/19 11:06:32 by cterblan         ###   ########.fr       */
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
	
	ptr1 = ft_malloc(10);
	ptr2 = ft_malloc(10);
	ptr3 = ft_malloc(10);
	ptr4 = ft_malloc(10);

	ft_free(ptr2);
	show_alloc_mem();
	ft_free(ptr4);
	ft_free(ptr3);
	ft_free(ptr1);
    return (0);
}