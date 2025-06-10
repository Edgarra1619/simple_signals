/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:12:47 by edgribei          #+#    #+#             */
/*   Updated: 2025/04/17 18:06:40 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc
#include <stdint.h> //SIZE_MAX
#include "libft.h"	//ft_bzero

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb)
		if (SIZE_MAX / nmemb < size)
			return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	str_size;

	str_size = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * str_size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, str_size);
	return (str);
}
