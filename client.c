/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:08:14 by vboxuser          #+#    #+#             */
/*   Updated: 2025/04/14 22:37:31 by dicosta-         ###   ########.fr       */
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
	}
}

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	struct	sigaction	act;
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
	act.sa_handler = receive_signal;
	
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL));
	return (EXIT_SUCCESS);
}
