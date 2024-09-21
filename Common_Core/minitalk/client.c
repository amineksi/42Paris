/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:06:27 by amine             #+#    #+#             */
/*   Updated: 2024/09/22 00:24:25 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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

int main(int argc, char *argv[])
{
	int			i;
	pid_t		pid;
	const char	*msg;
	
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