/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/06 18:18:59 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_caracter()
{
	
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else
		ft_printf("0");
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
		// ft_printf("%d\n", bin_number);
	}

	return (0);
}



// void	controlador(int	signal)
// {
// 	ft_printf("\nSeñal recibida: %d\n", signal);
// }

// void	handler(int signal)
// {
// 	if (signal == SIGUSR1)
// 		ft_printf("1");
// 	else
// 		ft_printf("0");
// }