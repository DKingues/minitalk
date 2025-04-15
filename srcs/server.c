/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:08:17 by vboxuser          #+#    #+#             */
/*   Updated: 2025/04/15 20:40:06 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *sa_mask)
{
	static int 	bit;
	static char c;
	__pid_t		client_pid;
	
	(void)sa_mask;
	bit = 0;
	c = 0;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		c = c << (bit | 1);
	}
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int		main(void)
{
	struct	sigaction	sa;
	__pid_t	pid;

	pid = getpid();

	ft_printf("SERVER PID: %d\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	while (1337)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}