/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:54:08 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/25 16:06:01 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "mlx.h"
# include "../libft/libft.h"

typedef struct			s_menu
{
	int					x;
	int					y;
	void				*img;
}						t_menu;

typedef struct			s_tex
{
	int					x;
	int					y;
	void				*img;
}						t_tex;

typedef struct			s_flag_menu
{
	int					pos;
	int					menu;
}						t_flag_menu;

typedef struct			s_flag
{
	int					fl_frw;
	int					fl_left;
	int					fl_rght;
	int					fl_back;
	int					shift;
}						t_flag;

typedef struct			s_read
{
	int					fd;
	int					i;
	int					j;
	int					c;
	int					w;
}						t_read;

typedef struct			s_game
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				time;
	double				oldtime;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					color;
	double				frametime;
	int					fps;
	double				movespeed;
	double				rotspeed;
	double				olddirx;
	double				oldplanex;
	int					texnum;
	double				wallx;
	int					texx;
	int					texy;
	int					x;
	int					y;
	int					d;
	double				floorxwall;
	double				floorywall;
	double				distwall;
	double				distplayer;
	double				currentdist;
	int					floor_tex_x;
	int					floor_tex_y;
	int					shift;
}						t_game;

typedef struct			s_wf
{
	char				**lvl1;
	char				**tmp1;
	void				*mlx;
	void				*win;
	void				*img;
	int					w_size_x;
	int					w_size_y;
	int					count;
	struct s_menu		*menu;
	struct s_tex		*tex;
	struct s_flag_menu	flmenu;
	struct s_flag		flag;
	struct s_read		read;
	struct s_game		game;
}						t_wf;

char					**ft_readfile(t_wf *wf);
t_wf					*ft_init_wf(void);
t_wf					*ft_init_game(t_wf *wf);
void					ft_menu(t_wf *wf);
void					ft_menu2(t_wf *wf);
void					ft_menu_lvl(t_wf *wf);
t_wf					*download_image(t_wf *wf);
int						ft_zaloop_hook(t_wf *wf);
void					raycasting(t_wf *wf);
int						ft_pix_get(t_wf *wf, int x, int y, int numtex);
void					ft_pix_put(t_wf *wf, int x, int y, int rgb);
void					ft_draw_line(t_wf *wf, int x);
int						button_release_game(int kcode, t_wf *wf);
int						button_release_menu2(int kcode, t_wf *wf);
int						button_press_suka(int kcode, t_wf *wf);
int						button_release_menu(int kcode, t_wf *wf);
int						button_release_level(int kcode, t_wf *wf);
int						button_release_control(int kcode, t_wf *wf);
t_wf					*calculate_speed_fps(t_wf *wf);
void					move_forward(t_wf *wf);
void					move_back(t_wf *wf);
void					move_left(t_wf *wf);
void					move_right(t_wf *wf);
void					action(t_wf *wf);
char					ft_chmo(t_wf *wf, int y, int x);
t_wf					*ft_init_flag(t_wf *wf);
t_wf					*ft_init_flag_menu(t_wf *wf);
void					draw_floors(t_wf *wf);
int						exit_x(void *par);
t_wf					*restart_game(t_wf *wf);
void					new_game_norma(t_wf *wf);

#endif
