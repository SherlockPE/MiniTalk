/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/15 14:56:08 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_perrror(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	convert_to_binary(int ascii_value, pid_t PID)
{
	int	error_case;
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(100);
		if (ascii_value & (1 << i))
			error_case = kill(PID, SIGUSR1);
		else
			error_case = kill(PID, SIGUSR2);
		if (error_case == -1)
			ft_perrror("No se encontró el PID especificado 🗿");
		i++;
		pause();
	}
}

void	handler_answer(int signal)
{
	static int	count;

	count++;
	if (signal == SIGUSR2)
		ft_printf("Message received, %d signals received\n", count);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	size_t	i;
	char	*message;

	if (argc <= 2)
		return (ft_printf("Argument not valid\n"), 0);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	signal(SIGUSR1, handler_answer);
	signal(SIGUSR2, handler_answer);
	while (i <= ft_strlen(message))
	{
		convert_to_binary(message[i], pid);
		i++;
	}
}
