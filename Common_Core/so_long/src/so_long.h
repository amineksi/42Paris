/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:42:18 by akassous          #+#    #+#             */
/*   Updated: 2025/01/12 12:13:08 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/mlx.h"
# include "../include/libft.h"
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*end_win;
	char	**map;
	int		count_e;
	int		count_p;
	int		count_c;
	int		x_begin_pos;
	int		y_begin_pos;
	int		x_end_pos;
	int		y_end_pos;
	int		count_moves;
	int		initial_count_c;
	void	*img_wall;
	void	*img_floor;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*winning_screen;
	void	*losing_screen;
	void	*alien;
}				t_vars;

void	cleanup_and_exit(t_vars *vars, int end);
char	**read_map(char *file_path);
int		map_conditions(t_vars *vars);
char	**error_handling(char *msg);
void	free_map(char **map);
int		existing_path(t_vars *vars);
int		ft_doublestrlen(char **map);
char	**checking_args(int argc, char *argv[]);
int		handle_close(t_vars *vars);
int		handle_key_press(int keycode, t_vars *vars);
void	load_images(t_vars *vars);
void	draw_map(t_vars *vars);
int		is_valid_cell(char **map, int x, int y, int **visited);
int		e_before_end(int x, int y, t_vars *vars);
void	end_screen(t_vars *vars, int won);
int		**fill_with_zeros(int **visited);
int		check_c_route(t_vars *vars, int x, int y, int **visited);
int		check_e_route(t_vars *vars, int x, int y, int **visited);
int		matching_size(char **map);
#endif
