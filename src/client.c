/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/11 18:37:55 by flopez-r         ###   ########.fr       */
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

int	main(int argc, char const *argv[])
{
	pid_t 	PID;
	// char	*message;


	//Check errors
	if (argc <= 2)
		return (ft_printf("Argument not valid\n"), 0);

	//Receive parameters
	PID = ft_atoi(argv[1]);

	//Sending message
	size_t i = 0;
	while (i <= ft_strlen(argv[2]))
	{
		convert_to_binary(argv[2][i], PID);
		// send_caracter(PID, binary_number);
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