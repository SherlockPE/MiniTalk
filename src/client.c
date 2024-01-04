/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/04 17:10:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char const *argv[])
{
	int		PID;
	char	*message;

	if (argc == 1)
		return (0);
	
	PID = ft_atoi(argv[1]);
	message = (char *)argv[2];

	ft_printf("%s", message);
}
