/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_wf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:41:00 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/15 19:39:07 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf		*ft_init_flag_menu(t_wf *wf)
{
	wf->flmenu.pos = 0;
	wf->flmenu.menu = 0;
	wf->read.i = 0;
	wf->read.j = 0;
	wf->read.c = 0;
	wf->read.w = 0;
	return (wf);
}

t_wf		*ft_init_flag(t_wf *wf)
{
	wf->flag.fl_frw = 0;
	wf->flag.fl_left = 0;
	wf->flag.fl_rght = 0;
	wf->flag.fl_back = 0;
	return (wf);
}

t_wf		*ft_init_game_resume(t_wf *wf)
{
	wf->game.drawstart = 0;
	wf->game.drawend = 0;
	wf->game.time = clock();
	wf->game.oldtime = clock();
	wf->game.frametime = 0;
	wf->game.movespeed = 0;
	wf->game.rotspeed = 0;
	return (wf);
}

t_wf		*ft_init_game(t_wf *wf)
{
	wf->game.posx = 22;
	wf->game.posy = 12;
	wf->game.dirx = -1;
	wf->game.diry = 0;
	wf->game.planex = 0;
	wf->game.planey = 0.66;
	wf->game.time = 0;
	wf->game.oldtime = 0;
	wf->game.camerax = 0;
	wf->game.rayposx = 0;
	wf->game.rayposy = 0;
	wf->game.raydirx = 0;
	wf->game.raydiry = 0;
	wf->game.mapx = 0;
	wf->game.mapy = 0;
	wf->game.sidedistx = 0;
	wf->game.sidedisty = 0;
	wf->game.deltadistx = 0;
	wf->game.deltadisty = 0;
	wf->game.perpwalldist = 0;
	wf->game.stepx = 0;
	wf->game.stepy = 0;
	wf->game.hit = 0;
	wf->game.side = 0;
	wf->game.lineheight = 0;
	wf = ft_init_game_resume(wf);
	return (wf);
}

t_wf		*ft_init_wf(void)
{
	t_wf	*wf;

	wf = (t_wf *)malloc(sizeof(t_wf));
	wf->w_size_x = 1024;
	wf->w_size_y = 768;
	wf->count = 0;
	wf->mlx = mlx_init();
	wf->win = mlx_new_window(wf->mlx, wf->w_size_x, wf->w_size_y, "wolf by LC");
	wf->img = mlx_new_image(wf->mlx, wf->w_size_x, wf->w_size_y);
	wf = ft_init_flag(wf);
	wf = ft_init_flag_menu(wf);
	wf = ft_init_game(wf);
	wf = download_image(wf);
	return (wf);
}
