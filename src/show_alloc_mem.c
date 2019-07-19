/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:18:54 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/19 15:44:04 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	*determine_size(t_type type)
{
	if (type == TINY)
		return ("TINY");
	else if (type == SMALL)
		return ("SMALL");
	else
		return ("LARGE");
}

void	show_alloc_mem(void)
{
	t_zone	*h_run;
	t_block	*b_run;
	size_t	total;

	total = 0;
	h_run = g_base;
	while (h_run)
	{
		ft_printf("%s : %p\n", determine_size(h_run->type), h_run->data);
		b_run = h_run->block_start;
		while (b_run)
		{
			ft_printf("%p - %p : %ld bytes\n", b_run->data,
			(b_run->data + b_run->size - 1), b_run->size);
			total += b_run->size;
			b_run = b_run->next;
		}
		h_run = h_run->next;
	}
	ft_printf("Total : %ld bytes\n", total);
}
