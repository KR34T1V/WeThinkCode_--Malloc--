/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:36 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/12 12:07:22 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  References
**  https://danluu.com/malloc-tutorial/
*/

#ifndef MALLOC_H
	#define MALLOC_H

	/*
	** Includes
	*/
	#include "../lib/libft/inc/libft.h"
	#include <unistd.h>

	/*
	** Defines
	*/
	typedef struct              s_block_meta {
		size_t                  size;
		int                     free;
		struct s_block_meta     *next;
		struct s_block_meta     *previous;
	}                           t_block_meta;

	typedef struct              s_zone {
		t_block_meta            *block;
		int					    *type;
		struct s_zone           *next;
		struct s_zone           *previous;
	}                           t_zone;
	
	#define 					ZONE_SIZE getpagesize()
	#define 					TINY 1
	#define 					SMALL 2
	#define 					LARGE 4
	#define						META_SIZE sizeof(t_block_meta)

	/*
	** Global Variables
	*/
	t_zone 					    *g_base;
	
	/*
	 ** Declarations
	 */
	void					    *malloc(size_t size);
	void					    show_alloc_mem();
	void					    free(void *ptr);
	void					    *realloc(void *ptr, size_t size);

#endif