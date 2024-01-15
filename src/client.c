/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/15 14:50:58 by flopez-r         ###   ########.fr       */
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
	int	i;
	int	error_case;

	i = 0;
	while (i < 8)
	{
		if (ascii_value & (1 << i))
			error_case = kill(PID, SIGUSR1);
		else
			error_case = kill(PID, SIGUSR2);
		if (error_case == -1)
			ft_perrror("No se encontró el PID especificado 🗿");
		i++;
		usleep(100);
	}
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;
	size_t	i;

	if (argc <= 2)
		return (ft_printf("Argument not valid\n"), 0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (i <= ft_strlen(argv[2]))
	{
		convert_to_binary(argv[2][i], pid);
		i++;
	}
}
