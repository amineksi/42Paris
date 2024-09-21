/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:14:37 by amine             #+#    #+#             */
/*   Updated: 2024/09/22 00:23:12 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void    send_signal(long int pid, unsigned char c)
{
    int				i;
	unsigned char	tmp;

	i = 7;
	while (i != -1)
	{
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
}

void	signalReceiver(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Bit 0 received succesfully.\n");
	else if (sig == SIGUSR2)
		ft_printf("Bit 1 received successfully.\n");
}
int main(int argc, char *argv[])
{
	int			i;
	pid_t		pid;
	const char	*msg;

	signal(SIGUSR1, signalReceiver);
    signal(SIGUSR2, signalReceiver);
	if (argc != 3 || ft_atoi(argv[1]) <= 0)
		write(2, "Error\n", 6);
	else
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (msg[i])
			send_signal(pid, msg[i++]);
		send_signal(pid, '\0');
	}
	return (0);
}