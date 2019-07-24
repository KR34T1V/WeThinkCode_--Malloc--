/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:18:16 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 12:49:42 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

void	free(void *ptr)
{
	t_zone	*h_run;
	t_block	*b_run;

	h_run = g_base;
	while (h_run)
	{
		b_run = h_run->block_start;
		while (b_run)
		{
			if (b_run->data == ptr)
			{
				block_free(h_run, b_run);
				break ;
			}
			b_run = b_run->next;
		}
		if (zone_free(h_run))
			break ;
		h_run = h_run->next;
	}
}
