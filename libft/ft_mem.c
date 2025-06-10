/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:26:31 by edgribei          #+#    #+#             */
/*   Updated: 2025/04/15 16:31:50 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *) s)[n - 1] = (unsigned char) c;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, const size_t n)
{
	const void	*fin = s + n;

	while (fin > s && (unsigned long) s % sizeof(long))
	{
		*((char *) s) = 0;
		s++;
	}
	while ((size_t) (fin - s) >= sizeof(long))
	{
		*((long *) s) = 0;
		s += sizeof(long);
	}
	if ((size_t)(fin - s) >= sizeof(int))
	{
		*((int *) s) = 0;
		s += sizeof(int);
	}
	if ((size_t)(fin - s) >= sizeof(short))
	{
		*((short *) s) = 0;
		s += sizeof(short);
	}
	if ((size_t)(fin - s) >= sizeof(char))
		*((short *) s) = 0;
}

//goes front to back
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
		return (ft_memcpy (dest, src, n));
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
