/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/15 11:59:13 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_bonus(int signal, siginfo_t *info, void *algo)
{
	static int	character;
	static int	num_bits;

	(void)algo;
	if (signal == SIGUSR1)
		character += (1 << num_bits);
	num_bits++;
	if (num_bits == 8)
	{
		if (character == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &character, 1);
		num_bits = 0;
		character = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	ss;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ss.sa_flags = SA_SIGINFO;
	ss.sa_sigaction = handler_bonus;
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
	{
	}
	return (0);
}
