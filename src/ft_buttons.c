/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:20:33 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/23 16:12:32 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	action(t_wf *wf)
{
	if (ft_chmo(wf,(int)(wf->game.posy + wf->game.diry), (int)(wf->game.posx + wf->game.dirx)) == '5')
		wf->lvl1[(int)(wf->game.posy + wf->game.diry)][(int)(wf->game.posx + wf->game.dirx)] = '0';
	else if (ft_chmo(wf,(int)(wf->game.posy + wf->game.diry), (int)(wf->game.posx + wf->game.dirx)) == '0')
		wf->lvl1[(int)(wf->game.posy + wf->game.diry)][(int)(wf->game.posx + wf->game.dirx)] = '5';
	else if (ft_chmo(wf,(int)(wf->game.posy + wf->game.diry), (int)(wf->game.posx + wf->game.dirx)) == '4')
		wf->flmenu.menu = 3;

}

void	move_forward(t_wf *wf)
{
	double		p_x;
	double		p_y;

	p_x = -wf->game.diry;
	p_y = wf->game.dirx;
	if (ft_chmo(wf,(int)(wf->game.posy), (int)(wf->game.posx + wf->game.dirx *
			wf->game.movespeed + 0.4 * wf->game.dirx)) <= '0')
	/*&&
		ft_chmo(wf,(int)(wf->game.posy), (int)(wf->game.posx + p_x *
				wf->game.movespeed + 0.4 * p_x)) <= '0' &&
		ft_chmo(wf,(int)(wf->game.posy), (int)(wf->game.posx - p_x *
				wf->game.movespeed - 0.4 * p_x)) <= '0')*/
		wf->game.posx += wf->game.dirx * wf->game.movespeed;
	if (ft_chmo(wf,(int)(wf->game.posy + wf->game.diry * wf->game.movespeed +
			0.4 * wf->game.diry),(int)(wf->game.posx)) <= '0')
	/* &&
		ft_chmo(wf,(int)(wf->game.posy + p_y * wf->game.movespeed +
				0.4 * p_y),(int)(wf->game.posx)) <= '0' &&
		ft_chmo(wf,(int)(wf->game.posy - p_y * wf->game.movespeed -
				0.4 * p_y),(int)(wf->game.posx)) <= '0')*/
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
