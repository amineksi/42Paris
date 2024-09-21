/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:14:04 by amine             #+#    #+#             */
/*   Updated: 2024/09/22 00:16:07 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void	signalHandler(int sig, siginfo_t *info, void *content)
{
	static	unsigned char	received_byte;
	static	int				bit_position;

	(void)content;
    received_byte |= (sig == SIGUSR2);
    bit_position++;
	if (bit_position == 8)
	{
		if (received_byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &received_byte, 1);
		bit_position = 0;
		received_byte = 0;
	}
	else
		received_byte <<= 1;
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int main(void)
{
	struct sigaction	sa;
	
	sa.sa_sigaction = signalHandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The server's PID is : %d\n", getpid());
	while (1)
		pause();
    return 0;
}