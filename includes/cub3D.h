/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:11:07 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/25 10:03:07 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <limits.h> 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "../Libft/libft.h"

# define BUFFER_SIZE 1
# define BLOCK_SIZE 16
# define WIDTH 1400
# define HEIGHT 800
# define MINIMAP_SIZE 0.3
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define LIMIT 3
# define INSECT_FRAMES 66
# define DRAGON_FRAMES 36
# define MONSTER_FRAMES 60
# define MOON_FRAMES 66
# define EPSILON 0.2
# define DRAGON 0
# define INSECT 1
# define MONSTER 2
# define MOON 3
# define NUM_RAYS WIDTH
# define RIGHT -1
# define LEFT 1
# define UP 1
# define DOWN -1
# define CLOSE 0
# define OPEN 1
# define HORIZ 0
# define VERT 1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_texture_put
{
	int		x;
	int		y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_texture_put;

typedef struct s_point
{
	double	x;
	double	y;
	int		hit;
}				t_point;

typedef struct s_door
{
	double	centre_x;
	double	centre_y;
	int		posit_x;
	int		posit_y;
	double	min_distance;
	int		visible;
	int		is_door;
	int		is_open_door;
}				t_door;

typedef struct s_sprite
{
	t_point		position;
	t_point		centre_position;
	int			visible;
	int			type;
	double		distance;
	double		angle;
}				t_sprite;

typedef struct s_sprite_utils
{
	double	ennemi_height;
	double	ennemi_width;
	double	y_top_ennemi;
	double	y_bottom_ennemi;
	double	ennemi_angle;
	double	x_ennemi;
	double	x_left_ennemi;
	double	x_right_ennemi;
	double	pixel_width;
	double	distance_from_top_y;
	int		x_offset;
	int		y_offset;
	int		x;
	int		y;
}				t_sprite_utils;

typedef struct s_rays
{
	double	x;
	double	y;
	double	distance;
	int		type;
}					t_rays;

typedef struct s_texture
{
	char				*direction;
	char				*path;
	struct s_texture	*next;
}					t_texture;

typedef struct s_color
{
	char			*identifier;
	int				r;
	int				g;
	int				b;
	struct s_color	*next;
}				t_color;

typedef struct s_face_directions
{
	int	facing_up;
	int	facing_down;
	int	facing_left;
	int	facing_right;
}			t_face_directions;

typedef struct s_horiz_intersec
{
	double	x_horiz;
	double	y_horiz;
	int		is_hit_horiz;
	double	xsteps;
	double	ysteps;
	double	xintersec;
	double	yintersec;
	double	xintersec_next;
	double	yintersec_next;
	double	x_check;
	double	y_check;
	double	horiz_distance;
	double	hx;
	double	hy;
}			t_horiz_intersec;

typedef struct s_vert_intersec
{
	double	x_vert;
	double	y_vert;
	int		is_hit_vert;
	double	xsteps;
	double	ysteps;
	double	xintersec;
	double	yintersec;
	double	xintersec_next;
	double	yintersec_next;
	double	x_check;
	double	y_check;
	double	vert_distance;
	double	vx;
	double	vy;
}			t_vert_intersec;

typedef struct s_map
{
	t_point				player;
	double				fov;
	double				rotation_speed;
	double				walk_speed;
	double				dist_proj_plane;
	int					turn;
	int					walk;
	int					show_minimap;
	double				move;
	int					line_count;
	int					z_pixel;
	char				**map;
	void				*mlx_ptr;
	void				*mlx_win;
	t_data				mlx_img;
	t_data				mlx_minimap;
	t_texture_put		texture_north;
	t_texture_put		texture_south;
	t_texture_put		texture_west;
	t_texture_put		texture_east;
	int					texture_offset_x;
	int					texture_offset_y;
	t_color				*color;
	t_texture			*texture;
	double				wall_height;
	t_face_directions	facing;
	t_horiz_intersec	horiz;
	t_vert_intersec		vert;
	t_rays				*ray;
	double				rotation_angle;
	int					ennemi_count;
	t_sprite			*ennemi;
	int					visible_ennemis;
	t_texture_put		insect_tex_1;
	t_texture_put		insect_tex_2;
	t_texture_put		insect_tex_3;
	t_texture_put		insect_tex_4;
	t_texture_put		insect_tex_5;
	t_texture_put		insect_tex_6;
	t_texture_put		insect_tex_7;
	t_texture_put		insect_tex_8;
	t_texture_put		insect_tex_9;
	t_texture_put		insect_tex_10;
	t_texture_put		insect_tex_11;
	double				insect_frame;
	t_texture_put		dragon_tex_1;
	t_texture_put		dragon_tex_2;
	t_texture_put		dragon_tex_3;
	t_texture_put		dragon_tex_4;
	t_texture_put		dragon_tex_5;
	t_texture_put		dragon_tex_6;
	double				dragon_frame;
	t_texture_put		monster_tex_1;
	t_texture_put		monster_tex_2;
	t_texture_put		monster_tex_3;
	t_texture_put		monster_tex_4;
	t_texture_put		monster_tex_5;
	t_texture_put		monster_tex_6;
	double				monster_frame;
	t_texture_put		moon_tex_1;
	t_texture_put		moon_tex_2;
	t_texture_put		moon_tex_3;
	t_texture_put		moon_tex_4;
	t_texture_put		moon_tex_5;
	t_texture_put		moon_tex_6;
	t_texture_put		moon_tex_7;
	t_texture_put		moon_tex_8;
	t_texture_put		moon_tex_9;
	t_texture_put		moon_tex_10;
	t_texture_put		moon_tex_11;
	double				moon_frame;
	t_texture_put		door_tex_1;
	t_door				*doors;
	int					doors_count;
}						t_map;

typedef struct s_tools
{
	int		i;
	int		j;
	int		count;
	int		fd;
	char	*line;
	char	**input;
	char	*str;
	char	*temp;
	char	*tmp;
}				t_tools;

char		*get_next_line(int fd);
int			ft_str_chr(char *str, char c);
char		*get_next_line(int fd);
int			file_parsing(char **argv, t_map	*map);
int			ft_str_chr(char *str, char c);
char		*ft_strdupn(char *s);
int			ft_isempty(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_integer(char *str);
int			number_of_commas(char *str);
int			ft_lstadd_color(t_color **color, t_color *newc);
t_color		*ft_newcolor(char *str, char *identifier);
int			get_color(char *str);
void		print_colors(t_map map);
int			check_double_color(t_map *map);
void		clear_colors(t_map *map);
int			ft_lstadd_texture(t_texture **texture, t_texture *newt);
t_texture	*ft_newtexture(char *direction, char *path);
void		print_textures(t_map map);
int			check_double_texture(t_map *map);
void		clear_textures(t_map *map);
int			get_map(t_map *map, char *file_name, char *str, int nb_lines);
char		**read_file(char **argv);
int			valid_map(int line_count, char **map, t_tools tools);
int			realloc_map(t_map *map);
int			allocate_map(t_map *map, char *file_name, char *str, int nb_lines);
int			valid_characters(char **map);
int			valid_line(char *line);
int			check_valid_door(char **map);
int			check_valid_sprite(char **map);
int			create_color_texture_list(char **temp, t_map *map);
int			valid_input(char *input, t_map *map);
int			split_file_content(t_tools *tools);
int			file_parsing(char **argv, t_map	*map);
int			valid_file_content(t_tools *tools, t_map *map, char **argv);
int			read_colors_textures(t_tools *tools, t_map *map);
int			ft_initialize(t_map *map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			start_drawing(t_map *map);
int			get_sprites_tex(t_map *map);
int			get_textures(t_map *map);
int			get_moon_tex(t_map *map);
int			get_monster_tex(t_map *map);
int			get_dragon_tex(t_map *map);
int			get_door_tex(t_map *map);
int			get_insect_tex(t_map *map);
void		draw_map(t_map *map);
int			is_wall(t_map *map, double x, double y);
double		fix_angle(double angle);
t_sprite	*search_visible_ennemi(t_map *map, t_sprite *ennemi);
void		put_ennemi(t_map *map, t_texture_put ennemi_tex, \
t_sprite visible_ennemi);
int			get_rgb(t_map *map, char *identifier);
void		render_walls(t_map *map, double ray_angle, int nb_ray);
double		two_points_dis(double x1, double y1, double x2, double y2);
int			mouse_hook(int x, int y, void *param);
int			keyup_hook(int key, void *mlx);
int			key_hook(int key, void *mlx);
double		fix_angle(double angle);
void		mlx_draw_line(double px, double py, t_map *map);
void		mlx_draw_circle(int px, int py, int color, t_map *map);
void		destroy_textures(t_map *map);
int			ft_close(t_map *map);
void		cilling_floor(t_map *map, int nb_ray, double wall_top, \
double wall_bottom);
void		draw_projected_wall(t_map *map, int nb_ray, t_texture_put texture);
int			on_hited_door(t_map *map, double x, double y);
int			wall_colision(t_map *map, double x, double y);
int			is_wall(t_map *map, double x, double y);
void		horiz_intersec(t_map *map, double ray_angle);
void		vert_intersec(t_map *map, double ray_angle);
void		mlx_draw_minimap(t_map *map);
void		init_sprite_door_info(t_map *map);
void		animate_insect(t_map *map, t_sprite visible_ennemi, double a);
void		animate_dragon(t_map *map, t_sprite visible_ennemi, double b);
void		animate_monster(t_map *map, t_sprite visible_ennemi, double c);
void		animate_moon(t_map *map, t_sprite visible_ennemi, double d);
int			animate_ennemi(t_map *map);
t_sprite	*search_visible_ennemi(t_map *map, t_sprite *ennemi);

#endif
