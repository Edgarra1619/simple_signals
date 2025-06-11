/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:08:05 by edgribei          #+#    #+#             */
/*   Updated: 2025/06/11 15:08:27 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#ifdef BONUS

static void	handler(const int signal, siginfo_t *const info,
			void *const _cont)
{
	static int	c = 0;
	static char	offset = 0;
	static int	current_pid;

	(void) _cont;
	if (!current_pid)
		current_pid = info->si_pid;
	if (current_pid != info->si_pid)
		return ;
	c = (c << 1) | (signal == SIGUSR2);
	if (++offset == 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			kill(current_pid, SIGUSR2);
			current_pid = 0;
		}
		c = 0;
		offset = 0;
	}
	if (current_pid)
		kill(current_pid, SIGUSR1);
}

#else

static void	handler(const int signal, siginfo_t *const info,
			void *const _cont)
{
	static int	c = 0;
	static char	offset = 0;
	static int	current_pid = 0;

	(void) _cont;
	if (!current_pid)
		current_pid = info->si_pid;
	if (current_pid != info->si_pid)
		return ;
	c = (c << 1) | (signal == SIGUSR2);
	if (++offset == 8)
	{
		write(1, &c, 1);
		if (!c)
			current_pid = 0;
		c = 0;
		offset = 0;
	}
}

#endif

static struct sigaction	init_sig(void)
{
	struct sigaction	sig;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = set;
	sig.sa_sigaction = handler;
	return (sig);
}

int	main(void)
{
	const struct sigaction	sig = init_sig();

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
