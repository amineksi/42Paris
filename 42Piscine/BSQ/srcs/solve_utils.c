/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:27:23 by akassous          #+#    #+#             */
/*   Updated: 2024/07/17 18:20:18 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/point.h"

void	assign_values(int i, int j, int **dp)
{
	if (i == 0 || j == 0)
		dp[i][j] = 1;
	else
		dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
}
