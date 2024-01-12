/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/12 16:06:09 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_binary(int ascii_value, pid_t PID)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (ascii_value & (1 << i))
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	handler_answer(int signal)
{
	ft_printf("Message received: %d\n", signal);
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
	while (i <= ft_strlen(message))
	{
		convert_to_binary(message[i], pid);
		i++;
	}
}

// void	convert_to_binary(int number, int *binary_number)
// {
// 	int	add_units;

// 	add_units = 1;
// 	while (number > 0)
// 	{
// 		*binary_number += (number % 2) * add_units;
// 		number /= 2;
// 		add_units *= 10;
// 	}
// }

// void	send_caracter(pid_t PID, int	binary_number)
// {
// 	int	i;
// 	char	*message;

// 	(void)PID;
// 	message = ft_itoa(binary_number);
// 	//PROTEJER ESTE MENSAJE
// 	ft_printf("%s\n", message);
// 	i = 0;
// 	while (message[i])
// 	{
// 		if (message[i] == '1')
// 			kill(PID, SIGUSR1);
// 		else if (message[i] == '0')
// 			kill(PID, SIGUSR2);
// 		usleep(10);
// 		i++;
// 	}
// 	free(message);
// }

// int signal = ft_atoi(argv[2]);

// if (signal == 0)
// 	kill(PID, SIGINT);
// else if (signal == 1)
// 	kill(PID, SIGSTOP);
// else if (signal == 2)
// 	kill(PID, SIGCONT);
// else
// 	ft_printf("Argument not valid\n");