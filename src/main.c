/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:56 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/25 11:44:16 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include "../includes/private_malloc_includes.h"

int main (){
	char *str;

	str = (char *)malloc(sizeof(char *) * 20);
	for (int i = 0; i<19; i++){
		str[i] = 'a';
	}
	str[19] = '\0';
	ft_printf("%s\n",str);
	realloc(str, 400);
	for (int i = 0; i<399; i++){
		str[i] = 'a';
	}
	str[399] = '\0';
	ft_printf("%s\n",str);
	free(str);
	show_alloc_mem();
    return (0);
}