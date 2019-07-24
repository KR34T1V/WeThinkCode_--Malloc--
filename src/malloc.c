/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:51:00 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 11:44:12 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE_MALLOC
#include "../includes/malloc.h"
#include "../includes/global.h"
#include "../includes/private_malloc_includes.h"

void	*malloc(size_t size)
{
	t_zone	*current;
	t_block	*new_block;

	if (size <= 0)
		return (NULL);
	current = zone_find(size);
	new_block = block_new(current, size);
	return (new_block->data);
}
