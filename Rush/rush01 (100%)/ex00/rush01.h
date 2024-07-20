/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:38:53 by oztozdem          #+#    #+#             */
/*   Updated: 2024/07/07 21:57:11 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	free_tab(char **tab);
void	free_all(char **values, char **tab);
void	ajout_vals(char *str, char **values, int i, int j);
void	init_vals(char *str, char **values);
void	init_tab(char *str, char **tab);
void	ft_print(char **tab, int max);
int		ft_strlen(char *str);
int		get_max_int(char *str);
int		error(char *str);
int		check_row_left(char **tab, char **values, int row, int max);
int		check_row_right(char **tab, char **values, int row, int max);
int		check_col_up(char **tab, char **values, int col, int max);
int		check_col_down(char **tab, char **values, int col, int max);
int		is_valid(char **tab, char **values, int max);
int		placeable(char **tab, int row, int col, int height);
int		base_algorithm(char **tab, char **values, int row, int col);

#endif