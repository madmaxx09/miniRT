/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:39:08 by mdor              #+#    #+#             */
/*   Updated: 2024/11/05 22:39:15 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRT.h"

void	print_image(t_rgb *img, t_data *data)
{
	int	i;
	int	j;

	printf("printing\n");
	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			mlx_put_pixel(data->mlx_image,
				i, j, rgb_to_color(img[j * WIDTH + i]));
			i++;
		}
		i = 0;
		j++;
	}
}

void	assign_img(t_data *data, t_rgb *denoised)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			data->image[j * WIDTH + i] = denoised[j * WIDTH + i];
			i++;
		}
		i = 0;
		j++;
	}
}
