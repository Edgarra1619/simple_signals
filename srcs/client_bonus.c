/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:08:37 by edgribei          #+#    #+#             */
/*   Updated: 2025/06/11 15:09:59 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//here to filter incoming signals
int		g_serverpid;

void	send_message(const int pid, const char *message);

void	handle(const int signal, siginfo_t *const info,
			void *const _cont)
{
	(void) _cont;
	if (g_serverpid != info->si_pid)
		return ;
	if (signal == SIGUSR1)
		send_message(g_serverpid, NULL);
	else
	{
		write(1, "Message Sent :D\n", 17);
		exit(1);
	}
}

int	send_bit(const int pid, const char c)
{
	static char	i;

	kill(pid, SIGUSR1 + 2 * ((c >> (7 - i)) & 1));
	if (++i == 8)
	{
		i = 0;
		return (1);
	}
	return (0);
}

void	send_message(const int pid, const char *message)
{
	static const char	*msg;

	if (message)
		msg = message;
	if (send_bit(pid, *msg))
		msg++;
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	sigset_t			set;

	if (argc != 3)
		return (1);
	g_serverpid = ft_atoi(argv[1]);
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = set;
	sig.sa_sigaction = handle;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	send_message(g_serverpid, argv[2]);
	while (1)
		pause();
	return (0);
}
