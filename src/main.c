/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/16 18:28:58 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int main (){
	unsigned long zone_size = getpagesize()*15;
	fflush(stdout);
	void *ptr;
	printf("HEAP MSize = %ld\nBlock MSize = %ld\nPage size: %zu\n", HEAP_META_SIZE, BLOCK_META_SIZE, ZONE_SIZE);
	ptr = ft_malloc(10);
	ptr = ft_malloc(54);
	ptr = ft_malloc(981);
    return (0);
}