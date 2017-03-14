/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:54:08 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/14 17:47:48 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"

typedef struct			s_menu
{
	int					i;
	int					j;
	void				*img;
}						t_menu;

typedef struct			s_flag_menu
{
	int					pos;
}						t_flag_menu;

typedef struct			s_flag
{
	int					menu;
}						t_flag;

typedef struct			s_read
{
	int					fd;
	//int					fd2;
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

}						t_game;

typedef struct			s_wf
{
	char				**lvl1;
	//char				**lvl2;
	void				*mlx;
	void				*win;
	void				*img;
	int					w_size_x;
	int					w_size_y;
	int					count;
	struct s_menu		*menu;
	struct s_flag		flag;
	struct s_read		read;
	struct s_game		game;
	struct s_flag_menu	flmenu;
}						t_wf;

char					**ft_readfile(t_wf *wf);
t_wf					*ft_init_wf(void);
void					ft_menu(t_wf *wf);
t_wf					*download_image(t_wf *wf);
int						ft_zaloop_hook(t_wf *wf);
void					raycasting(t_wf *wf);
void					ft_draw_line(t_wf *wf, int x);

#endif
