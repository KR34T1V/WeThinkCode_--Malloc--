/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:38:47 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/19 16:08:26 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*fuck_norm(void *ptr, size_t size, t_zone *h_run, t_block *b_run)
{
	void	*keeper;

	if (b_run->data == ptr)
	{
		if (((unsigned int)((int64_t)b_run->next - (int64_t)
		b_run->data - 1) >= size) && h_run->type == zone_type(size))
		{
			b_run->size = size;
			return (ptr);
		}
		else
		{
			keeper = ft_malloc(size);
			ft_memcpy(keeper, ptr, b_run->size);
			ft_free(ptr);
			return (keeper);
		}
	}
	return (NULL);
}

void		*ft_realloc(void *ptr, size_t size)
{
	t_zone	*h_run;
	t_block	*b_run;
	void	*keeper;

	keeper = NULL;
	h_run = g_base;
	while (h_run)
	{
		b_run = h_run->block_start;
		while (b_run)
		{
			if ((keeper = fuck_norm(ptr, size, h_run, b_run)))
				return (keeper);
			b_run = b_run->next;
		}
		h_run = h_run->next;
	}
	return (NULL);
}
