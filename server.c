/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:08:17 by vboxuser          #+#    #+#             */
/*   Updated: 2025/04/14 18:31:56 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		main(void)
{
	__pid_t	pid;

	pid = getpid();

	ft_printf("SERVER PID: %d\n", pid);
	while (1337)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}