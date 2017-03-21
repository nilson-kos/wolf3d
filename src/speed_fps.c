/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:36:05 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/20 13:49:04 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf	*calculate_speed_fps(t_wf *wf)
{
	wf->game.oldtime = wf->game.time;
	wf->game.time = clock();
	wf->game.frametime = (wf->game.time - wf->game.oldtime) / CLOCKS_PER_SEC;
	wf->game.fps = (int)(1.0 / wf->game.frametime);
	//ft_putnbr(wf->game.fps);
	//ft_putchar('\n');
	mlx_string_put(wf->mlx, wf->win, 5, 10, 0xFF0000,
			ft_strjoin("fps : ", ft_itoa(wf->game.fps)));
	wf->game.movespeed = wf->game.frametime * 2.0;
	//printf("ms = %f\n", wf->game.movespeed);
	wf->game.rotspeed = wf->game.frametime * 1.0;
	return (wf);
}
