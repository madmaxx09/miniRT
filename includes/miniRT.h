/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:56:16 by mdor              #+#    #+#             */
/*   Updated: 2024/11/13 19:09:23 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libmlx/include/MLX42/MLX42.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "structs.h"
# include "mymath.h"
# define WIDTH 1000
# define HEIGHT 750.0
# define MAX_DEPTH 5 //amount of bounces per ray
# define SAMPLE 10 //number of ray shots per pixel
# define DENOISE_PASS 1 //number of passes of the final image in the denoising function
# define DENOISE_SIGMA 0.5 //the strength of the denoising 0 (weak : pixelised) 1 (strong : blurry) 
# define DENOISE_SAMPLE 2.0
# define BLACK_TRESHHOLD 0.8
# define SQUARE_SIDE 5.0
# define SQUARE_AREA 25.0
# define EPSILON 1e-8
# define PI 3.14159265
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 666
# endif

void	ft_error_exit(char *str, t_data *data, char **tab);
void	*gc_malloc(size_t required_memory, t_data *data);
t_rgb	ray(t_vec origine, t_vec direction, int depth, t_data *data);
void	get_viewport(t_data *data);
void	print_image(t_rgb *img, t_data *data);
bool	is_black(t_rgb pixel);
void	assign_img(t_data *data, t_rgb *denoised);
t_rgb	color_ray(t_data *data, int i, int j, t_rgb *blend);

//hit functions
void	sphere_check(t_sphere *sp, t_hit *hit, t_vec ori, t_vec dir);
void	plane_check(t_plan *pl, t_hit *hit, t_vec ori, t_vec dir);
void	cyl_check(t_cyl *cyl, t_hit *hit, t_vec ori, t_vec dir);
void	disc_check(t_disc *disc, t_hit *hit, t_vec ori, t_vec dir);
t_vec	get_obj_normal(t_hit *hit);
t_hit	hit_box(t_vec ori, t_vec dir, t_data *data);
double	hit_sp(t_vec ori, t_vec direction, t_sphere *sphere);
double	hit_pl(t_vec ori, t_vec dir, t_plan *plan);
double	hit_cyl(t_vec ori, t_vec dir, t_cyl *cyl, double t_max);
double	hit_disc(t_vec ori, t_vec dir, t_disc *disc, double t_max);
t_vec	normal_cyl(t_vec pos, t_vec dir, t_vec point);
t_vec	get_new_dir(t_hit *hit);
double	scatter_pdf(t_hit *hit);
void	denoise_and_render(t_data *data);
//Parsing functions
int		ft_atob(const char *str, int b_p, int a_p, double *res);
void	parse_rt(char *rt_file, t_data *data);
void	manage_rgb(char **tab, t_rgb *store, t_data *data, int pos);
void	manage_vectors(char **tab, t_vec *store, t_data *data, int pos);
void	free_tabl(char **tab);
void	manage_ambiant(char **tab, t_data *data, int split_count);
void	manage_cam(char **tab, t_data *data, int split_count);
void	manage_light(char **tab, t_data *data, int split_count);
void	manage_sphere(char **tab, t_data *data, int split_count);
void	manage_plan(char **tab, t_data *data, int split_count);
void	manage_cyl(char **tab, t_data *data, int split_count);
void	manage_background(char **tab, t_data *data, int split_count);
int		presskey(int key, t_data *data);
void	raytrace(t_data *data);
void	add_cyl(t_data *data, t_cyl *cyl);
void	add_sph(t_data *data, t_sphere *sph);
void	add_pl(t_data *data, t_plan *pln);
void	free_custom_alloc(t_data *data);

#endif
