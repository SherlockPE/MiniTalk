/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/09 14:35:00 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_list *binary;


void	handler(int signal)
{
	ft_printf("LLEGUÉ AQUÍ");
	if (signal == SIGUSR1)
		sig_add_back(&binary, sig_new(1));
	else if (signal == SIGUSR2)
		sig_add_back(&binary, sig_new(0));
	print_sig_lst(binary);
}


int	main(void)
{
	int		PID;

	PID = getpid();
	ft_printf("PID: %d\n", PID);
	ft_printf("MINITALK PRUEBA\n");

	binary = NULL;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	while (1)
	{
	}

	return (0);
}










/* void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else if (signal == SIGUSR2)
		ft_printf("0");
} */














// void	handler(int signal)
// {
// 	static	int	value;
// 	static	int	result;
// 	static	int	iterations;

// 	value = 64;
// 	result = 0;
// 	iterations = 7;

// 	if (value != 0)
// 	{
// 		if (signal == SIGUSR1)
// 		{
// 			result += value;
// 			ft_printf("1 - %d - %d\n", value, result);
// 			return ;
// 		}
// 		else
// 		{
// 			ft_printf("0 - %d - %d\n", value, result);
// 			return ;
// 		}
// 	}
// 	value /= 2;
// 	printf("\nValor final: %d\n", result);
// }
// void	handler(int signal)
// {
// 	if (signal == SIGUSR1)
// 		ft_printf("1");
// 	else if (signal == SIGUSR2)
// 		ft_printf("0");
// }

// void	print_list(t_list	*byte)
// {
// 	while (byte)
// 	{
// 		ft_printf("%d", *(int *)byte->content);
// 		byte = byte->next;
// 	}
// 	ft_printf("\n");
// }

// void	handler(int signal)
// {
// 	int	*content;

// 	ft_printf("Señal recibida: %d\n", signal);


// 	//Assign memory to content
// 	content = malloc(sizeof(int));
// 	if (!content)
// 	{
// 		ft_lstclear(&byte, free);
// 		return ;
// 	}

// 	//Assign value to content
// 	if (signal == SIGUSR1)
// 		*content = 1;
// 	else if (signal == SIGUSR2)
// 		*content = 0;


// 	//Añadir elemento a la lista
// 	while (ft_lstsize(byte) <= 7)
// 	{
// 		ft_lstadd_back(&byte, ft_lstnew(content));
// 		print_list(byte);
		
// 	}

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