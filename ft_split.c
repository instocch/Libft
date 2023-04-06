/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:15:43 by mstocche          #+#    #+#             */
/*   Updated: 2023/04/04 15:44:25 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (0);
}

void	ft_len_word(const char *s, char c, int *word_len, int *c_count)
{
	int	i;

	i = 0;
	*word_len = 0;
	*c_count = 0;
	while (s[i] != '\0' && s[i] == c)
	{
		(*c_count)++;
		i++;
	}
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		(*word_len)++;
	}
}

char	*ft_putword(char *dest, const char *src, int len_word, int c_counter)
{
	int	word;
	int	i;

	word = 0;
	i = c_counter;
	while (word < len_word)
	{
		dest[word] = src[i];
		i++;
		word++;
	}
	dest[word] = '\0';
	return (dest);
}

static char	**ft_split_word(char **str, const char *s, char c, int num_words)
{
	int	i;
	int	word;
	int	word_len;
	int	c_counter;

	i = 0;
	word = 0;
	while (word < num_words)
	{
		ft_len_word(&s[i], c, &word_len, &c_counter);
		str[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!str[word])
			return (ft_free(str, word));
		ft_putword(str[word], &s[i], word_len, c_counter);
		i += word_len + c_counter;
		word++;
	}
	str[word] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	num_words;
	int				i;

	i = 0;
	num_words = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num_words++;
		i++;
	}
	str = (char **) malloc(sizeof(char *) * (num_words + 1));
	if (!str)
		return (NULL);
	str = ft_split_word(str, s, c, num_words);
	str[num_words] = NULL;
	return (str);
}
