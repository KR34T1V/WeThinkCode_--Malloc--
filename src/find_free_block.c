/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_free_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:59:31 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/15 20:59:32 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block_meta				*find_free_block(size_t size, size_t type)
{
	t_zone			*h_run;
	t_block_meta	*b_run;

	while (h_run){
		if (h_run->type == type){
			b_run = h_run->blocks;
			while (b_run){
				if (b_run->freed == 1 && b_run->size >= size)
					return(b_run);
				b_run = b_run->next;
			}
		}
		h_run = h_run->next;
	}
	return (NULL);
}