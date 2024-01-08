/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/08 16:05:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_binary(int number, int *binary_number)
{
	int	add_units;

	add_units = 1;
	while (number > 0)
	{
		*binary_number += (number % 2) * add_units;
		number /= 2;
		add_units *= 10;
	}
}

void	send_caracter(pid_t PID, int	binary_number)
{
	int	i;
	char	*message;
	
	(void)PID;
	message = ft_itoa(binary_number);

	i = 0;
	while (message[i])
	{
		if (message[i] == '1')
			kill(PID, SIGUSR1);
		else if (message[i] == '0')
			kill(PID, SIGUSR2);
		usleep(10);
		i++;
	}
	
}

int	main(int argc, char const *argv[])
{
	pid_t 	PID;
	int		binary_number;
	char	*message;


	//Check errors
	if (argc == 1)
		return (ft_printf("Argument not valid\n"), 0);

	//Receive parameters
	PID = ft_atoi(argv[1]);
	message = (char *)argv[2];

	//Sending message
	int i = 0;
	while (message[i])
	{
		binary_number = 0;
		convert_to_binary((unsigned char)message[i], &binary_number);
		send_caracter(PID, binary_number);
		i++;
	}

}

// int signal = ft_atoi(argv[2]);

// if (signal == 0)
// 	kill(PID, SIGINT);
// else if (signal == 1)
// 	kill(PID, SIGSTOP);
// else if (signal == 2)
// 	kill(PID, SIGCONT);
// else
// 	ft_printf("Argument not valid\n");