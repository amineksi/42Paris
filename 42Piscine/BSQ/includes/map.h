/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:23:36 by bdenfir           #+#    #+#             */
/*   Updated: 2024/07/16 20:23:36 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**data;
}	t_map;

int		free_map(t_map *map);
void	find_biggest_square(t_map *map);
void	print_map(t_map *map);
void	ft_puterror(char *str);
void	assign_values(int i, int j, int **dp);
void	ft_putstr(char *str);
int		**__init__(t_map *map);
int		min(int a, int b, int c);
int		check_maps(int fd, t_map *map);
int		get_length(char *buffer);
int		check_line(char *line, t_map *map, int line_count);
int		parse_map_details(char *buffer, t_map *map);
int		create_map(char *buffer, t_map *map);
int		check_free(t_map *map, int line_count);
char	**allocate_map_data(int rows, int cols);

t_map	*read_map(int fd);
t_map	*read_map_from_stdin(void);
t_map	*read_map_from_file(const char *filename);

# define BUFFER_SIZE 1048576

#endif
