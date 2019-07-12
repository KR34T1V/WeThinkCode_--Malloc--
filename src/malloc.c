/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:46:05 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/12 12:13:15 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void    *malloc(size_t size){

    if (size <= 0){
        return (0);
    }

    //If Current Page Has Enough space for the size

    //If not enough request new page

}