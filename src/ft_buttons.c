/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:20:33 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/15 21:47:08 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_forward(t_wf *wf)
{
	if (wf->lvl1[(int)(wf->game.posx + wf->game.dirx * wf->game.movespeed)]
			[(int)(wf->game.posy)] == '0')
	{
		//printf("gopa\n");
		wf->game.posx += wf->game.dirx * wf->game.movespeed;
	}
	if (wf->lvl1[(int)(wf->game.posx)]
			[(int)(wf->game.posy + wf->game.diry * wf->game.movespeed)] == '0')
	{
		//printf("gopa2\n");
		wf->game.posy += wf->game.diry * wf->game.movespeed;
	}
}

void	move_back(t_wf *wf)
{
	if (wf->lvl1[(int)(wf->game.posx - wf->game.dirx * wf->game.movespeed)]
			[(int)(wf->game.posy)] == '0')
	{
		//printf("gopa\n");
		wf->game.posx -= wf->game.dirx * wf->game.movespeed;
	}
	if (wf->lvl1[(int)(wf->game.posx)]
			[(int)(wf->game.posy - wf->game.diry * wf->game.movespeed)] == '0')
	{
		//printf("gopa2\n");
		wf->game.posy -= wf->game.diry * wf->game.movespeed;
	}
}

void	move_left(t_wf *wf)
{
	
}

void	move_right(t_wf *wf)
{

}
