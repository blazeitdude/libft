/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:18:44 by ldione            #+#    #+#             */
/*   Updated: 2022/09/13 20:21:53 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
void    *ft_realloc(void *inp, int size, int len)
{
	void	*dst;
	
	free(inp);
	dst = malloc(size * len);
	ft_bzero(dst, len);
	return (dst);
}