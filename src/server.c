/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/08 16:15:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else if (signal == SIGUSR2)
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



// void	print_list(t_list	*byte)
// {
// 	while (byte)
// 	{
// 		ft_printf("%s", *(char *)byte->content);
// 		byte = byte->next;
// 	}
// 	ft_printf("\n");
// }

// void	bin_to_caracter(char	*character)
// {
// 	char	*aux;

// 	aux = byte_character;
// 	byte_character = ft_strjoin(byte_character, character);
	
// 	int len = ft_strlen(byte_character);
// 	if (len == 7)
// 	{
// 		ft_printf("%s\n", byte_character);
// 		free(byte_character);
// 		byte_character = "";
// 	}
	
// 	free(aux);
// }

	// if (signal == SIGUSR1)
	// 	bin_to_caracter("1");
	// else if (signal == SIGUSR2)
	// 	bin_to_caracter("0");
	// else
	// 	ft_printf("\nSignal received: %d\n", signal);

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