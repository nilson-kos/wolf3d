/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:54:03 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/20 18:01:01 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	create_texture(t_wf *wf, int numtex)
{
	if (wf->game.side == 0)
		wf->game.wallx = wf->game.rayposy + wf->game.perpwalldist *
				wf->game.raydiry;
	else
		wf->game.wallx = wf->game.rayposx + wf->game.perpwalldist *
				wf->game.raydirx;
	wf->game.wallx -=floor((wf->game.wallx));
	//double(texwidth)
	wf->game.texx = (int)(wf->game.wallx * wf->tex[numtex].x);
	if (wf->game.side == 0 && wf->game.raydirx > 0)
		wf->game.texx = wf->tex[numtex].x - wf->game.texx - 1;
	if (wf->game.side == 1 && wf->game.raydiry < 0)
		wf->game.texx = wf->tex[numtex].x - wf->game.texx - 1;
	wf->game.y = wf->game.drawstart;
	while (wf->game.y < wf->game.drawend)
	{
		wf->game.d = wf->game.y * 2 - wf->w_size_y +
			wf->game.lineheight;
		wf->game.texy = ((wf->game.d * wf->tex[numtex].y) /
			wf->game.lineheight) / 2;
		wf->game.color = ft_pix_get(wf, wf->game.texx, wf->game.texy, numtex);
		ft_pix_put(wf, wf->game.x, wf->game.y, wf->game.color);
		wf->game.y++;
	}
}

void		side_dist(t_wf *wf)
{
	if (wf->game.raydirx < 0)
	{
		wf->game.stepx = -1;
		wf->game.sidedistx = (wf->game.rayposx - wf->game.mapx) *
							wf->game.deltadistx;
	}
	else
	{
		wf->game.stepx = 1;
		wf->game.sidedistx = (wf->game.mapx + 1.0 - wf->game.rayposx) *
							wf->game.deltadistx;
	}
	if (wf->game.raydiry < 0)
	{
		wf->game.stepy = -1;
		wf->game.sidedisty = (wf->game.rayposy - wf->game.mapy) *
							wf->game.deltadisty;
	}
	else
	{
		wf->game.stepy = 1;
		wf->game.sidedisty = (wf->game.mapy + 1.0 - wf->game.rayposy) *
							wf->game.deltadisty;
	}
}

void		hit(t_wf *wf)
{
	while (wf->game.hit == 0)
	{
		if (wf->game.sidedistx < wf->game.sidedisty)
		{
			wf->game.sidedistx += wf->game.deltadistx;
			wf->game.mapx += wf->game.stepx;
			wf->game.side = 0;
		}
		else
		{
			wf->game.sidedisty += wf->game.deltadisty;
			wf->game.mapy += wf->game.stepy;
			wf->game.side = 1;
		}
		if (ft_chmo(wf, wf->game.mapy, wf->game.mapx) > '0')
			wf->game.hit = 1;
	}
	if (wf->game.side == 0)
		wf->game.perpwalldist = (wf->game.mapx - wf->game.rayposx +
				(1 - wf->game.stepx) / 2) / wf->game.raydirx;
	else
		wf->game.perpwalldist = (wf->game.mapy - wf->game.rayposy +
			(1 - wf->game.stepy) / 2) / wf->game.raydiry;
}


void		last(t_wf *wf)
{
	wf->game.lineheight = (int)(wf->w_size_y / wf->game.perpwalldist);
	wf->game.drawstart = -wf->game.lineheight / 2 + wf->w_size_y / 2;
	if (wf->game.drawstart < 0)
		wf->game.drawstart = 0;
	wf->game.drawend = wf->game.lineheight / 2 + wf->w_size_y / 2;
	if (wf->game.drawend >= wf->w_size_y)
		wf->game.drawend = wf->w_size_y - 1;
}

void		raycasting(t_wf *wf)
{
	wf->game.x = 0;
	wf->game.y = 0;
	wf->game.d = 0;
	while (wf->game.x < wf->w_size_x)
	{
		wf->game.camerax = 2 * 	wf->game.x / (double)wf->w_size_x - 1;
		wf->game.rayposx = wf->game.posx;
		wf->game.rayposy = wf->game.posy;
		wf->game.raydirx = wf->game.dirx + wf->game.planex * wf->game.camerax;
		wf->game.raydiry = wf->game.diry + wf->game.planey * wf->game.camerax;
		wf->game.mapx = (int)wf->game.rayposx;
		wf->game.mapy = (int)wf->game.rayposy;
		wf->game.deltadistx = sqrt(1 + (wf->game.raydiry * wf->game.raydiry) /
								(wf->game.raydirx * wf->game.raydirx));
		wf->game.deltadisty = sqrt(1 + (wf->game.raydirx * wf->game.raydirx) /
								(wf->game.raydiry * wf->game.raydiry));
		wf->game.hit = 0;
		side_dist(wf);
		hit(wf);
		last(wf);
		wf->game.texnum = wf->lvl1[wf->game.mapy][wf->game.mapx] - '1';
		//wf->game.texnum = ft_chmo(wf, wf->game.mapy, wf->game.mapx) - '1';
		create_texture(wf, wf->game.texnum);
		draw_floors(wf);
		wf->game.x++;
	}
	mlx_put_image_to_window(wf->mlx, wf->win, wf->img, 0, 0);
}
