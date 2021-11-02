/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:08:55 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/11/01 15:10:58 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define BUFFER_SIZE    4096
# define MY_PI 3.14159265
# define MY_TWO_PI 6.28318530
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 800

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	int		walk_side;
}	t_player;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_line
{
	int	begin_x;
	int	begin_y;
	int	end_x;
	int	end_y;
	int	color;
}	t_line;

typedef struct s_text
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_text;

typedef struct s_data
{
	char		**map;
	int			dx;
	int			dy;
	char		*e_s;
	char		*w;
	char		*e;
	char		*c;
	char		*p;
	int			tex_dev;
	int			moov_count;
	int			erreur;
	int			lignevide;
	int			insidemap;
	int			wrongcharmap;
	int			nblines;
	int			sizeline;
	int			count;
	char		depart;
	int			indicateur3;
	int			multijoueurs;
	int			window_width;
	int			window_height;
	void		*mlx_ptr;
	void		*win_ptr;
	double		tile_size;
	t_text		texture[5];
	t_img		img;
	t_player	player;
}	t_data;

int		ft_so_long(char *str, t_data *recup);
int		ft_strlen(char *str);
void	ft_error(t_data *recup, char *str);
void	ft_parsing(char *fichier, t_data *recup);
void	ft_initialisation(t_data *recup);
int		ft_map_dir_rony_check(char *fichier, t_data *recup);
int		get_next_line(int fd, char **line, t_data *recup);
void	ft_swap_line(char **line, char *temp);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_subbuff(char *buff, int start, int len);
void	ft_map(char *str, t_data *recup);
int		ft_is_map(char *str, t_data *recup);
int		ft_charinstr(char *str, char c);
int		ft_lignevide(char *str);
int		ft_copy_map(char *str, t_data *recup);
int		ft_depart(char c, t_data *recup, int i, int j);
int		ft_mlx(t_data *data);
int		ft_init(t_data *data);
void	ft_setup(t_data *data);
int		ft_handle_destroynotify(t_data *data);
int		ft_handle_keypress(int keysym, t_data *data);
int		ft_handle_keyrelease(int keysym, t_data *data);
void	ft_img_pix_put(t_img *img, int x, int y, int color);
void	ft_render_background(t_data *data, int color);
int		ft_exit(t_data *recup);
void	ft_render_map(t_data *data);
void	ft_render_player(t_data *data);
int		ft_draw_line(t_img *img, t_line line);
void	ft_normalize_angle(float *angle);
int		ft_map_has_wall_at(t_data *recup, float x, float y);
void	ft_get_textures(t_data *data);
int		ft_render_map_pix(t_data *data, t_rect rect, int k);
int		ft_text_num(t_data *data, int i, int j);
void	ft_verify_errors(t_data *recup);
int		ft_murs(t_data *recup);
int		ft_murs_util(char *str);
int		ft_c_e_ckeck(t_data *recup, char c);
void	ft_move_count(t_data *data, int new_player_dx, int new_player_dy);
void	ft_map_copy(t_data *recup, char *str);
int		ft_gnl_cpy(int ret, char *buff, char **line);
int		ft_copy(char **line, char **buff);
#endif
