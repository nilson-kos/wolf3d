/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:36:05 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/25 15:50:37 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		*ft_jf(char *str1, char *str2)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (res);
}

void		str_free(char *str, t_wf *wf)
{
	mlx_string_put(wf->mlx, wf->win, 5, 10, 0xFF0000, str);
	free(str);
}

t_wf		*calculate_speed_fps(t_wf *wf)
{
	wf->game.oldtime = wf->game.time;
	wf->game.time = clock();
	wf->game.frametime = (wf->game.time - wf->game.oldtime) / CLOCKS_PER_SEC;
	wf->game.fps = (int)(1.0 / wf->game.frametime);
	str_free(ft_jf(ft_strdup("fps : "), ft_itoa(wf->game.fps)), wf);
	wf->game.movespeed = wf->game.frametime * 2.0 * wf->game.shift;
	wf->game.rotspeed = wf->game.frametime * 1.5;
	return (wf);
}
