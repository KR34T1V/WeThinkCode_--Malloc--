/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:48:23 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/15 21:48:24 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*new_zone(size_t type){
	t_zone			*current;
	t_zone			*previous;
	
	current = g_base;
	while (current){
			previous = current;
			current = current->next;
	}
	if ((current = (t_zone *)mmap(0, HEAP_META, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED)
		return (NULL);
	current->type = type;
	current->previous = previous;
	current->next= NULL;
	return (current);
}