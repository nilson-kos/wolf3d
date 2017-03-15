/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:54:03 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/15 16:58:48 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		raycasting(t_wf *wf)
{
	int		x;

	x = 0;
	//printf("strc = %d\n", wf->read.w);
	while (x < wf->w_size_x)
	{
		//printf("x=%d size_x=%d\n", x, wf->w_size_x);
		wf->game.camerax = 2 * x / (double)wf->w_size_x - 1;
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
			if (wf->lvl1[wf->game.mapy][wf->game.mapx] > '0')
				wf->game.hit = 1;
		}
		// printf("SIDE=%D\n", wf->game.side);
		// printf("XXXXmapx=%d rayposx=%f stepx=%d raydirx=%f\n", wf->game.mapx,wf->game.rayposx,wf->game.stepx,wf->game.raydirx);
		// printf("YYYYmapx=%d rayposx=%f stepx=%d raydirx=%f\n", wf->game.mapy,wf->game.rayposy,wf->game.stepy,wf->game.raydiry);
		if (wf->game.side == 0)
			wf->game.perpwalldist = (wf->game.mapx - wf->game.rayposx +
					(1 - wf->game.stepx) / 2) / wf->game.raydirx;
		else
			wf->game.perpwalldist = (wf->game.mapy - wf->game.rayposy +
				(1 - wf->game.stepy) / 2) / wf->game.raydiry;
		// printf("pwd=%f=" ,wf->game.perpwalldist);
		wf->game.lineheight = (int)(wf->w_size_y / wf->game.perpwalldist);
		// printf("lh=%d=" ,wf->game.lineheight);
		wf->game.drawstart = -wf->game.lineheight / 2 + wf->w_size_y / 2;
		if (wf->game.drawstart < 0)
			wf->game.drawstart = 0;
		// printf("%d=" ,wf->game.drawend);
		wf->game.drawend = wf->game.lineheight / 2 + wf->w_size_y / 2;
		if (wf->game.drawend >= wf->w_size_y)
			wf->game.drawend = wf->w_size_y - 1;

		if (wf->lvl1[wf->game.mapx][wf->game.mapy] == '1')
			wf->game.color = 0xFF00FF;
		else
			wf->game.color = 0xFFFFFF;

		//if (wf->game.side == 1)
			//wf->game.color = wf->game.color / 2;

		ft_draw_line(wf, x);
		x++;

	}
	mlx_put_image_to_window(wf->mlx, wf->win, wf->img, 0, 0);

}
