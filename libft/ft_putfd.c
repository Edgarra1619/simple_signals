/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:50:10 by edgribei          #+#    #+#             */
/*   Updated: 2025/04/15 15:25:24 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	const char		dgts[10] = "0123456789";
	long			nb;
	unsigned int	pot;

	nb = nbr;
	if (nbr < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	pot = 1;
	while (nb / pot > 9)
		pot *= 10;
	while (pot)
	{
		write(fd, dgts + ((nb / pot) % 10), 1);
		pot /= 10;
	}
}
