/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/15 12:23:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_title(void)
{
	int	pid;

	pid = getpid();
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
	ft_printf("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("PID: %d\n", pid);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
}

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
		write(1, &character, 1);
		num_bits = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
	pause();
}

int	main(void)
{
	struct sigaction	signal_action;

	print_title();
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = handler_bonus;
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while (1)
	{
	}
	return (0);
}
