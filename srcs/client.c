#include <libft.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//here to filter incoming signals
int	g_serverpid;

void	handle(const int signal, siginfo_t *const info,
			void *const _cont)
{
	(void) _cont;

	if (g_serverpid != info->si_pid)
		return ;
	if(signal == SIGUSR1)
	{
		write(2, "Server is Busy :(\n", 18);
		exit(1);
	}
	else
	{
		write(1, "Message Sent :D\n", 17);
		exit(1);
	}
}

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

#ifdef BONUS
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
	sleep(1);
	write(2, "I think something went wrong :(\n", 32);
	send_char(g_serverpid, 0);
	return (0);
}
#else
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	g_serverpid = ft_atoi(argv[1]);
	send_message(g_serverpid, argv[2]);
	return (0);
}

#endif
