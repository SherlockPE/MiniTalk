/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:20 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/09 16:20:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "minitalk.h"

void	print_listas(t_list *header_a)
{
	printf("---------------------------------\n");
	printf("		Stack of bits		:\n");
	while (header_a)
	{
		printf("%i\n", *(int *)header_a->content);
		header_a = header_a->next;
	}
	printf("---------------------------------\n");
}


/* void	print_sig_lst(sig_list	*header)
{
	while (header)
	{
		ft_printf("%d", header->content);
		header = header->next;
	}
	ft_printf("\n");
}

void	sig_add_back(sig_list   **lst,  sig_list *new)
{
	sig_list    *temp;

	temp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}

	while (temp)
		temp = temp->next;
	temp->next = new;
}

sig_list	*sig_new(int	content)
{
	sig_list	*new_element;

	new_element = (sig_list *)malloc(sizeof(sig_list));
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
 */