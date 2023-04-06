/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:49:39 by mstocche          #+#    #+#             */
/*   Updated: 2023/04/05 12:18:18 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	buffer = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		buffer[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		buffer[j++] = s2[i];
		i++;
	}
	buffer[j] = 0;
	return (buffer);
}
