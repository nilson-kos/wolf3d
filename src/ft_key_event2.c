/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:44:07 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/25 16:03:16 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		button_release_control(int kcode, t_wf *wf)
{
	(kcode == 53) ? wf->flmenu.menu = 0 : 777;
	return (0);
}

void	new_game_norma(t_wf *wf)
{
	wf = ft_init_game(wf);
	wf->flmenu.pos = 0;
	wf = restart_game(wf);
	wf->game.posx = 2;
	wf->game.posy = 2;
	wf = ft_init_flag(wf);
	wf->flmenu.menu = 1;
}
