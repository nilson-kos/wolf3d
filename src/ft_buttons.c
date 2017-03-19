/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:20:33 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/19 19:53:59 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	ft_chmo(t_wf *wf, int y, int x)
{
	if ((y < 0 || x < 0) || x >= wf->read.w - 1 || y >= wf->count - 1)
		return (127);
	return (wf->lvl1[y][x]);
}

void	move_forward(t_wf *wf)
{
	if (ft_chmo(wf,(int)(wf->game.posy),(int)(wf->game.posx + wf->game.dirx *
			wf->game.movespeed + 0.4 * wf->game.dirx)) <= '0')
		wf->game.posx += wf->game.dirx * wf->game.movespeed;
	if (ft_chmo(wf,(int)(wf->game.posy + wf->game.diry * wf->game.movespeed +
			0.4 * wf->game.diry),(int)(wf->game.posx)) <= '0')
		wf->game.posy += wf->game.diry * wf->game.movespeed;
}

void	move_back(t_wf *wf)
{
	if (ft_chmo(wf, (int)(wf->game.posy), (int)(wf->game.posx -
			wf->game.dirx * wf->game.movespeed - 0.4 * wf->game.dirx)) <= '0')
		wf->game.posx -= wf->game.dirx * wf->game.movespeed;
	if (ft_chmo(wf,(int)(wf->game.posy - wf->game.diry * wf->game.movespeed -
			0.4 * wf->game.diry),(int)(wf->game.posx)) <= '0')
		wf->game.posy -= wf->game.diry * wf->game.movespeed;
}

void	move_right(t_wf *wf)
{
	wf->game.olddirx = wf->game.dirx;
	wf->game.dirx = wf->game.dirx * cos(-wf->game.rotspeed) - wf->game.diry *
		sin(-wf->game.rotspeed);
	wf->game.diry = wf->game.olddirx * sin(-wf->game.rotspeed) + wf->game.diry *
		cos(-wf->game.rotspeed);
	wf->game.oldplanex = wf->game.planex;
	wf->game.planex = wf->game.planex * cos(-wf->game.rotspeed) -
		wf->game.planey * sin(-wf->game.rotspeed);
	wf->game.planey = wf->game.oldplanex * sin(-wf->game.rotspeed) +
		wf->game.planey * cos(-wf->game.rotspeed);
}

void	move_left(t_wf *wf)
{
	wf->game.olddirx = wf->game.dirx;
	wf->game.dirx = wf->game.dirx * cos(wf->game.rotspeed) - wf->game.diry *
		sin(wf->game.rotspeed);
	wf->game.diry = wf->game.olddirx * sin(wf->game.rotspeed) + wf->game.diry *
		cos(wf->game.rotspeed);
	wf->game.oldplanex = wf->game.planex;
	wf->game.planex = wf->game.planex * cos(wf->game.rotspeed) -
		wf->game.planey * sin(wf->game.rotspeed);
	wf->game.planey = wf->game.oldplanex * sin(wf->game.rotspeed) +
		wf->game.planey * cos(wf->game.rotspeed);
}
