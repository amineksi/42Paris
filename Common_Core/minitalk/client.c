/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:06:27 by amine             #+#    #+#             */
/*   Updated: 2024/09/21 01:12:31 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_signal(long int pid, char c)
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
		usleep(100);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int			i;
	pid_t		pid;
	const char	*msg;
	
	i = 0;
	pid = atoi(argv[1]);
	msg = argv[2];
	while (msg[i])
		send_signal(pid, msg[i++]);
	send_signal(pid, '\0');
	return (0);
}