/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:36 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/24 15:48:32 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

/*
** Includes
*/
# include "../lib/libft/inc/export_ft_printf.h"
# include <sys/types.h>

/*
** Defines
*/
typedef enum	e_type{
	TINY = 0,
	SMALL = 1,
	LARGE = 2
}				t_type;

typedef struct				s_block{
	void					*data;
	size_t					size;
	struct s_block			*next;
	struct s_block			*previous;
}							t_block;

typedef struct				s_zone{
	t_type					type;
	size_t					size;
	t_block					*block_start;
	void					*data;
	struct s_zone			*next;
	struct s_zone			*previous;
}							t_zone;

# define HEAP_META_SIZE sizeof(t_zone)
# define BLOCK_META_SIZE sizeof(t_zone)
# define ZONE_SIZE getpagesize()
# define TINY_SIZE 32
# define SMALL_SIZE 128
# define FIT_ZONE(S) (((S) / ZONE_SIZE) + 1) * ZONE_SIZE
# define TINY_ZONE FIT_ZONE(((TINY_SIZE+BLOCK_META_SIZE)*100)+HEAP_META_SIZE)
# define SMALL_ZONE FIT_ZONE(((SMALL_SIZE+BLOCK_META_SIZE)*100)+HEAP_META_SIZE)

/*
** Global Variables
*/
# ifndef BASE_MALLOC

extern t_zone *g_base;
# endif

/*
** Declarations
*/
void						*malloc(size_t size);
void						show_alloc_mem();
void						free(void *ptr);
void						*realloc(void *ptr, size_t size);

t_zone						*zone_find(size_t size);
t_zone						*zone_new(size_t size);
t_type						zone_type(size_t size);
int							zone_free(t_zone *zone);
t_block						*block_new(t_zone *zone, size_t size);
void						block_free(t_zone *zone, t_block *block);

#endif
