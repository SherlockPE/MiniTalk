/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/10 18:53:05 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*result;

void	print_character(void)
{
	int		ascci_value;
	int		actual_bit;

	ascci_value = 0;
	actual_bit = 64;
	while (*result)
	{
		if (*result == '1')
			ascci_value += actual_bit;
		actual_bit /= 2;
		result++;
	}
	ft_printf("\n ASCII VALUE: %d\n", ascci_value);
	// ft_printf("%c", ascci_value);
	result = ft_strdup("");
}

void	handler(int signal)
{
	char	*aux;

	if (!result)
		result = ft_strdup("");
	aux = result;
	if (signal == SIGUSR1)
		result = ft_strjoin(result, "1");
	else if (signal == SIGUSR2)
		result = ft_strjoin(result, "0");
	// ft_printf("%s\n", result);
	if (ft_strlen(result) == 7)
		print_character();
	free(aux);
}

int	main(void)
{
	int					PID;
	struct sigaction	ss;
	sigset_t			signals;

	PID = getpid();
	ft_printf("PID: %d\n", PID);
	// Create mask
	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	ss.sa_handler = handler;
	// Listener
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
	{
	}
	return (0);
}
// int		result;

/* void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("%d", 1);
	else if (signal == SIGUSR2)
		ft_printf("%d", 0);
}
 */

/* void	handler(int signal)
{
	static int	bit_values = 64;
	if (signal == SIGUSR1)
		result += bit_values;
	bit_values = bit_values / 2;
	ft_printf("\nValor en ascii: %d\n", result);
} */

// signal(SIGUSR1, handler);
// signal(SIGUSR2, handler);
// t_list	*byte_value;

// void	handler(int signal)
// {
// 	int	*content;

// 	content = (int *)malloc(sizeof(int));
// 	if (signal == SIGUSR1)
// 		*content = 1;
// 	else if (signal == SIGUSR2)
// 		*content = 0;
// 	ft_lstadd_back(&byte_value, ft_lstnew(content));
// 	print_listas(byte_value);
// }

// sig_list *binary;
// t_list	*numbers;

// void	handler(int signal)
// {
// 	int	*content;

// 	content = (int *)ft_calloc(1, sizeof(int));

// 	ft_printf("LLEGUÉ AQUÍ S:%d\n", signal);
// 	if (signal == SIGUSR1)
// 		*content = 1;
// 		// sig_add_back(&binary, sig_new(1));
// 	else if (signal == SIGUSR2)
// 		*content = 2;
// 		// sig_add_back(&binary, sig_new(0));
// 	ft_lstadd_back(&numbers, ft_lstnew(content));
// 	print_listas(numbers, 0);
// 	// print_sig_lst(binary);
// }

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