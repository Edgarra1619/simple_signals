/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:05:49 by edgribei          #+#    #+#             */
/*   Updated: 2025/04/17 13:50:09 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	strsize;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	strsize = ft_strlen(s1);
	while (ft_strchr(set, s1[strsize - 1]) && strsize)
		strsize--;
	str = ft_calloc(strsize + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, strsize + 1);
	return (str);
}

static size_t	ft_count_words(const char *s, char c)
{
	_Bool	in_word;
	size_t	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
				count++;
			in_word = 0;
		}
		else
			in_word = 1;
		s++;
	}
	return (count + in_word);
}

static void	*free_array(void **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

static char	*endofword(const char *s, char c)
{
	char	*end;

	end = ft_strchr(s, c);
	if (end)
		return (end);
	return (ft_strchr(s, 0));
}

char	**ft_split(const char *s, char c)
{
	char	**out;
	size_t	count;
	size_t	size;

	count = ft_count_words(s, c);
	out = ft_calloc(count + 1, sizeof(char *));
	if (!out || count == 0)
		return (out);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			size = endofword(s, c) - s + 1;
			out[count] = ft_calloc(size, sizeof(char));
			if (!out[count])
				return (free_array((void **) out));
			ft_strlcpy(out[count++], s, size);
			s += size - 1;
		}
		else
			s++;
	}
	return (out);
}
