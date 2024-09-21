/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:14:04 by amine             #+#    #+#             */
/*   Updated: 2024/09/21 23:14:18 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void	signalHandler(int sig)
{
	static	unsigned char	received_byte;
	static	int				bit_position;
	
    received_byte |= (sig == SIGUSR2);
    bit_position++;
	if (bit_position == 8)
	{
		if (received_byte == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", received_byte);
		bit_position = 0;
		received_byte = 0;
	}
	else
		received_byte <<= 1; 
}

int main(void)
{
	ft_printf("The server's PID is : %d\n", getpid());
    signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	while (1)
		pause();
    return 0;
}