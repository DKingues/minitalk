/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:08:14 by vboxuser          #+#    #+#             */
/*   Updated: 2025/04/15 20:45:55 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	send_char(char c, int pid)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(TIME);
	}
}

void receive_signal(int signal)
{
	int i;
	
	i = 0;
	if (signal == SIGUSR1 && i == 0)
	{
		ft_putendl_fd("Message received by server.", 1);
		i = 1;	
	}
}

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	struct	sigaction	sa;
	int					pid;
	char 				*message;
	
	if (argc != 3)
		error_message("ERROR.\nExample: ./program_name PID \"MESSAGE\"\n");
	pid = ft_atoi(argv[1]);
	message = argv[2];
	if (message[0] == 0 || pid <= 0)
		error_message("ERROR: Invalid PID or message.\n");
	while (*message)
		send_char(*message++, pid);
	send_char('\n', pid);
	sa.sa_handler = receive_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_message("ERROR");
	return (EXIT_SUCCESS);
}
