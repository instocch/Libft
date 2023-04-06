/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:22:58 by mstocche          #+#    #+#             */
/*   Updated: 2023/04/04 16:10:41 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	buffer = malloc(size * count);
	if (!buffer)
		return (NULL);
	ft_bzero (buffer, size * count);
	return (buffer);
}
