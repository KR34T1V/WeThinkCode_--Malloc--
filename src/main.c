/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/16 18:15:33 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int main (){
	unsigned long zone_size = getpagesize()*15;
	fflush(stdout);
	void *ptr;
	printf("Size = %ld\n", HEAP_META_SIZE);
	ptr = ft_malloc(10);
    return (0);
}