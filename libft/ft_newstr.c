/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:21:38 by edgribei          #+#    #+#             */
/*   Updated: 2025/04/17 13:49:54 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	while (i < start)
	{
		if (!s[i++])
		{
			str = ft_calloc(1, sizeof(char));
			return (str);
		}
	}
	i = 0;
	while (i < len && s[start + i])
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, i + 1);
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}

static void	parse_to_string(unsigned int n, int count, char *str)
{
	while (n)
	{
		str[count - 1] = '0' + (n % 10);
		count--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t			count;
	int				cpy;
	char			*str;

	cpy = n;
	count = n < 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (cpy)
	{
		count++;
		cpy /= 10;
	}
	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		parse_to_string(-n, count, str);
	}
	else
		parse_to_string(n, count, str);
	return (str);
}
