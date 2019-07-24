/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:51:03 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 11:44:21 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

t_type	zone_type(size_t size)
{
	if (size <= TINY_SIZE)
		return (TINY);
	else if (size <= SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}
