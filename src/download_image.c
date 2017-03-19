/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:12:29 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/19 20:26:46 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf	*download_menu(t_wf *wf)
{
	wf->menu = (t_menu *)malloc(sizeof(t_menu) * 2);
	wf->menu[0].img = mlx_xpm_file_to_image(wf->mlx,
		"img/menu1/newgamemenu.XPM", &wf->menu[0].x, &wf->menu[0].y);
	if (wf->menu[0].img == 0)
		perror("img/menu1/newgamemenu.XPM");
	wf->menu[1].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu1/quitmenu.XPM", &wf->menu[1].x, &wf->menu[1].y);
	if (wf->menu[1].img == 0)
		perror("img/menu1/quitmenu.XPM");
	//printf("i = %d, j = %d\n",wf->menu[1].x, wf->menu[1].y);
	return (wf);
}

t_wf	*download_tex(t_wf *wf)
{
	wf->tex = (t_tex *)malloc(sizeof(t_tex) * 2);
	wf->tex[0].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/basement.XPM", &wf->tex[0].x, &wf->tex[0].y);
	if (wf->tex[0].img == 0)
		perror("img/texture/basement.XPM");
	wf->tex[1].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/wood.XPM", &wf->tex[1].x, &wf->tex[1].y);

	return (wf);
}

t_wf	*download_image(t_wf *wf)
{
	wf = download_menu(wf);
	wf = download_tex(wf);
	return (wf);
}
