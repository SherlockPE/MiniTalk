/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/06 14:51:41 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pow(int *base, int exponent)
{
	if (base == 0 && exponent == 0)
	{
		*base = 0;
		return ;	
	}
	else if (exponent == 0)
	{
		*base = 1;
		return ;
	}
	while (exponent--)
		*base *= *base;
}

void	convert_to_binary(int	base)
{
	int	exponent;
	
	exponent = 7;
	while (base) 
	{
		/* code */
	}
}


int	main(int argc, char const *argv[])
{
	pid_t PID;
	char	*message;
	if (argc == 1)
		return (ft_printf("Argument not valid\n"), 0);

	//Receive parameters
	PID = ft_atoi(argv[1]);
	message = (char *)argv[2];

	//Sending message
	int i = 0;
	while (message[i])
	{
		convert_to_binary(message[i]);
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