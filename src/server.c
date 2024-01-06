/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/06 13:55:36 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	controlador(int	signal)
{
	ft_printf("\nSeñal recibida: %d\n", signal);
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1\n");
	else
		ft_printf("0\n");
}

int	main(void)
{
	int		PID;

	PID = getpid();
	ft_printf("PID: %d\n", PID);

	ft_printf("MINITALK PRUEBA\n");

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	while (1)
	{
	}
	

	// int i = 1;
	// while (i)
	// {
	// 	int j = 10;
	// 	while (j--)
	// 	{
	// 		ft_printf("%d ", i++);
	// 		sleep(1);
	// 	}
	// 	ft_printf("\n");
	// }

	return (0);
}
