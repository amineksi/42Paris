/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:21:46 by amine             #+#    #+#             */
/*   Updated: 2024/09/21 01:12:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signalHandler(int sig)
{
	static	unsigned char	received_byte;
	static	int				bit_position;
	
	received_byte |= (sig == SIGUSR2);
	bit_position++;
	if (bit_position == 8)
	{
		if (received_byte == '\0')
			write(1, "\n", 1);
		else
			printf("%c", received_byte);
		bit_position = 0;
		received_byte = 0;
	} 
	else
		received_byte <<= 1;
}

int main(void)
{
	printf("%d\n", getpid());
    signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	while (1)
		pause();
    return 0;
}