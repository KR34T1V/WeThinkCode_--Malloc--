/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:51:00 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/18 20:33:34 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE_MALLOC
#include "../includes/malloc.h"
#include "../includes/global.h"

//RENAME BACK TO MALLOC
void    *ft_malloc(size_t size){
	t_zone	*current;
	t_block	*new_block;

	if (size <= 0)
		return (NULL);
	current = zone_find(size);
	new_block = block_new(current, size);
	return (new_block->data);
}