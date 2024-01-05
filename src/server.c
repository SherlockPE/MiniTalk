/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/05 18:38:35 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	controlador(int	signal)
{
	ft_printf("\nSeñal recibida: %d\n", signal);
}


int	main(void)
{
	int		PID;

	PID = getpid();
	ft_printf("PID: %d\n", PID);

	ft_printf("MINITALK PRUEBA\n");

	int i = 1;
	while (i)
	{
		int j = 10;
		while (j--)
		{
			ft_printf("%d ", i++);
			sleep(1);
		}
		ft_printf("\n");
	}

	return (0);
}
