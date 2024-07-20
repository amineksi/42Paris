/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:58:07 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 23:09:15 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int board[10])
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	safe_pos(int board[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col)
			return (0);
		else if (board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	rec_loop(int board[10], int col, int *count)
{
	int	i;

	i = 0;
	if (col == 10)
	{
		print_board(board);
		(*count)++;
		return ;
	}
	while (i < 10)
	{
		if (safe_pos(board, i, col))
		{
			board[col] = i;
			rec_loop(board, col + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	board[10];
	int	count;

	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}	
	count = 0;
	rec_loop(board, 0, &count);
	return (count);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_ten_queens_puzzle());
return 5;
}*/
