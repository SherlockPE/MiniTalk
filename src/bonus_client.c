/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/15 11:28:06 by flopez-r         ###   ########.fr       */
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
	ft_printf("Message received correctly");
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
