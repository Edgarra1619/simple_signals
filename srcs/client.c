/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:04:57 by edgribei          #+#    #+#             */
/*   Updated: 2025/06/11 15:05:05 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_char(const int pid, const char c)
{
	char	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1 + 2 * ((c >> (7 - i)) & 1));
		i++;
		usleep(100);
	}
}

void	send_message(const int pid, const char *message)
{
	while (*message)
	{
		send_char(pid, *(message++));
		usleep(300);
	}
	send_char(pid, 0);
}

int	main(int argc, char **argv)
{
	int	serverpid;

	if (argc != 3)
		return (1);
	serverpid = ft_atoi(argv[1]);
	send_message(serverpid, argv[2]);
	return (0);
}
