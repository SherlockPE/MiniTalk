/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:40:44 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/09 17:10:47 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct minitalk
{
	int				content;
	struct minitalk	*next;
}					sig_list;

# include "../Libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// void				print_listas(t_list *header_a);
// void				print_sig_lst(sig_list *header);
// void				sig_add_back(sig_list **lst, sig_list *new);
// sig_list			*sig_new(int content);

#endif
