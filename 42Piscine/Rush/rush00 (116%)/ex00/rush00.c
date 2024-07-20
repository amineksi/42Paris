/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: akassous <marvin@42.fr>		    +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2024/06/29 11:28:45 by akassous	  #+#    #+#	     */
/*   Updated: 2024/06/29 13:36:21 by akassous         ###   ########.fr       */
/*									    */
/* ************************************************************************** */

void	ft_putchar(char c);

void	conditions(int x, int y, int line_idx, int col_idx)
{
	if (col_idx == 0 || col_idx == x - 1)
	{
		if (line_idx == 0 || line_idx == y - 1)
			ft_putchar('o');
		else
			ft_putchar('|');
	}
	else
	{
		if (line_idx == 0 || line_idx == y - 1)
			ft_putchar('-');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	line_idx;
	int	col_idx;

	line_idx = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (line_idx != y)
	{
		col_idx = 0;
		while (col_idx != x)
		{
			conditions(x, y, line_idx, col_idx);
			col_idx++;
		}
		line_idx++;
		ft_putchar('\n');
	}
}
