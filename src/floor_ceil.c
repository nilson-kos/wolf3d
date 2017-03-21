/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:38:56 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/21 17:14:58 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	pixel_on_floor(t_wf *wf, int y)
{
	int	color;

	color = ft_pix_get(wf, wf->game.floor_tex_x, wf->game.floor_tex_y, 2);
	ft_pix_put(wf, wf->game.x, y, color);
	color = ft_pix_get(wf, wf->game.floor_tex_x, wf->game.floor_tex_y, 3);
	ft_pix_put(wf, wf->game.x, wf->w_size_y - y, color);
}

void	draw_floor_res(t_wf *wf)
{
	int	y;
	double cur_dist;
	double cur_fl_x;
	double cur_fl_y;
	double weight;

	y = wf->game.drawend + 1;
	cur_dist = 0;
	cur_fl_x = 0;
	cur_fl_y = 0;
	weight = 0;
	while (y < wf->w_size_y)
	{
		cur_dist = wf->w_size_y / (2.0 * y - wf->w_size_y);
		weight = (cur_dist - wf->game.distplayer) / (wf->game.distwall - wf->game.distplayer);
		cur_fl_x = weight * wf->game.floorxwall + (1.0 - weight) * wf->game.posx;
		cur_fl_y = weight * wf->game.floorywall + (1.0 - weight) * wf->game.posy;
		wf->game.floor_tex_x = (int)(cur_fl_x * wf->tex[2].x) % wf->tex[2].x;
		wf->game.floor_tex_y = (int)(cur_fl_y * wf->tex[2].y) % wf->tex[2].y;
		pixel_on_floor(wf, y);
		y++;
	}

}

void	draw_floors(t_wf *wf)
{
	if (wf->game.side == 0 && wf->game.raydirx > 0)
	{
		wf->game.floorxwall = wf->game.mapx;
		wf->game.floorywall = wf->game.mapy + wf->game.wallx;
	}
	else if (wf->game.side == 0 && wf->game.raydirx < 0)
	{
		wf->game.floorxwall = wf->game.mapx + 1.0;
		wf->game.floorywall = wf->game.mapy + wf->game.wallx;
	}
	else if (wf->game.side == 1 && wf->game.raydiry > 0)
	{
		wf->game.floorxwall = wf->game.mapx + wf->game.wallx;
		wf->game.floorywall = wf->game.mapy;
	}
	else
	{
		wf->game.floorxwall = wf->game.mapx + wf->game.wallx;
		wf->game.floorywall = wf->game.mapy + 1.0;
	}
	wf->game.distwall = wf->game.perpwalldist;
	wf->game.distplayer = 0.0;
	if (wf->game.drawend < 0)
		wf->game.drawend = wf->w_size_y;
	draw_floor_res(wf);
}
