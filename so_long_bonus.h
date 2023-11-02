/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:25:20 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 14:22:25 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "mlx_linux/mlx.h"
// maths related functions
#include <math.h>
// file related functions (open, access)
#include <fcntl.h>
// wait(), waitpid()
#include <sys/wait.h>
// process-related functions (fork)
#include <sys/types.h>
// memory-related functions (malloc and free)
#include <stdlib.h>
// system calls (close, dup2, pipe, execve)
#include <unistd.h>
// standard input/output operations and perror
#include <stdio.h>

// define variables used - linux
#define IMG_SIZE 32
#define ESC 65307
#define Q 113
#define W 119
#define A 97
#define S 115
#define D 100
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

/* structure to handle map*/
typedef struct s_map
{
	char **map;
	void *obj;
	int x;
	int y;
	int collectible;
} t_map;

/* structure to store and check valid path*/
typedef struct s_check
{
	char **map;
	int len_x;
	int len_y;
	int p_x;
	int p_y;
} t_check;

/*structure to store the images*/
typedef struct s_img
{
	void *plyr;
	void *collectible;
	void *background;
	void *wall;
	void *exit;
} t_img;

/* structure to handle data*/
typedef struct s_data
{
	void *mlx;
	void *win;
	int height;
	int width;
	int p_x;
	int p_y;
	int counter;
	int collected;
	t_map map;
	t_img img;
} t_data;

// check_map.c
int ft_map_error(char *error);
int ft_check_borders(t_data *data);
int ft_check_requisites(int collectible, int player, int exit);
int ft_check_contents(t_data *data);
// check_path.c
void flood_fill(t_check *check, int x, int y);
t_check *check_map_init(t_data *data);
void ft_find_start(t_check *check);
int init_flood(t_data *data);
// check_path_utils
int check_path_map(t_check *check, int x, int y);
void free_check_map(t_check *check);
// checks.c
void ft_check_args(int argc);
void ft_check_fd(int fd);
void compare_length(int len, int next_len, int fd);
void ft_check_rows(int fd, int len);
void check_dim(int width, int height, int fd);
// count.c
int ft_linelen(int fd);
int ft_countlines(int fd);
int ft_count_requisites(t_data *data, int plyr, int exit);
// draw count
void ft_draw_count(t_data *data);
// free_memory.c
void ft_free_map(t_data *data);
void ft_free_memory(t_data *data);
// get_next_line
char *get_next_line(int fd);
char *read_to_str(int fd, char *left_str);
// get_next_line_utils
size_t gnl_strlen(char *str);
char *gnl_strchr(char *str, int c);
char *gnl_strjoin(char *left_str, char *buf);
char *ft_get_line(char *left_str);
char *update_left_str(char *left_str);
// map.c
void ft_get_size(t_data *data, char **argv);
int ft_parse_map(char **argv, t_data *data);
void ft_put_player(t_data *data);
void ft_put_object(t_data *data, void *img);
void ft_draw_map(t_data *data);
// map_utils
int ft_map_alloc(char **argv, t_data *data);
void ft_put_images(t_data *data, int new_x, int new_y);
void ft_put_background(t_data *data);
// play.c
int ft_set_y(char direction, int new_y);
int ft_set_x(char direction, int new_x);
void ft_check_collected(t_data *data);
void ft_move(t_data *data, char direction, int new_x, int new_y);
int ft_actions(int keycode, t_data *data);
// print_error
void ft_print_error(t_data *data, int code);
// so_long.c
void set_images(t_data *data);
int ft_close(t_data *data);
int ft_render_next_frame(t_data *data);
t_data *data(void);
// free map
void ft_free_map(t_data *data);

#endif
