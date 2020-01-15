/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:35:20 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:51:31 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "struct.h"

int		ft_printf(const char *str_format, ...);

t_arg	*new_t_arg(void);
int		print_str_format(t_arg *arg, const char *str_format, int len);

/*
** Récupération des données
*/
int		get_settings_for_t_arg(const char *str_format, t_arg *arg);
void	get_type_for_t_arg(t_arg *arg);
void	get_options_for_t_arg(t_arg *arg);
int		get_width_min_for_t_arg(t_arg *arg);
int		get_precision_for_t_arg(t_arg *arg);
void	get_flag_for_t_arg(t_arg *arg);
int		get_arg_for_t_arg(t_arg *arg_list, va_list args, t_dioux *dioux);
int		get_t_args(const char *str_format, t_arg *arg);

/*
** Traitement des données
*/
int		get_str_format(t_arg *arg, va_list args);
int		get_prefix(t_arg *arg_elem, char *arg);
char	*apply_precision(t_arg *arg_elem, char *arg);
int		get_arg_modified(t_arg *arg_elem, t_dioux *dioux);

/*
** %di
*/
int		get_arg_di(t_arg *arg_elem, va_list args, t_dioux *dioux);
char	*di_to_str(t_arg *arg_elem, t_dioux *dioux);
char	*apply_option_plus_to_di(t_arg *t_arg_elem, char *str, char *arg);
char	*apply_soustract_to_di(t_arg *t_arg_elem, char *arg, char *str);
char	*apply_option_space_to_di(t_arg *t_arg_elem, char *str, char *arg);
char	*apply_option_zero_to_di(t_arg *t_arg_elem, char *str, char *arg);
char	*apply_option_to_di(t_arg *arg_elem, char *str, char *arg);
char	*get_arg_modified_for_di(t_arg *arg_elem, t_dioux *diouxx);

/*
** %ouxX
*/
int		get_arg_uox(t_arg *arg_elem, va_list args, t_dioux *dioux);
char	*u_to_str(t_arg *arg_elem, t_dioux *dioux);
void	*oux_to_str(t_arg *arg, unsigned long long d, t_dioux *dioux);
char	*apply_option_to_u(t_arg *arg_elem, char *str, char *arg);
char	*apply_option_to_o(t_arg *arg_elem, char *str, char *arg);
char	*apply_option_to_x(t_arg *arg_elem, char *str, char *arg);
char	*get_arg_modified_for_oux(t_arg *arg_elem);

/*
** %cs
*/
int		get_arg_c(t_arg *arg_elem, va_list args);
int		get_arg_s(t_arg *arg_elem, va_list args);
int		get_utf8(wint_t wc1, wint_t *wc2, unsigned char len);
int		get_mask_utf8(char **mask_utf8, unsigned char len);
char	*get_arg_modified_for_cs(t_arg *arg_elem);
char	*apply_precision_for_s(t_arg *arg_elem, char *arg);
int		put_wstr(t_arg *arg_elem);
void	free_wchar_t(wchar_t **ws);
void	ft_putwint(wint_t *c);
int		ft_putwchar(t_arg *arg_elem, wchar_t **ws_ptr, int len);
int		wchar_len(wchar_t *ws);
int		octet_count(wchar_t **ws);
int		wchar_count(wchar_t **ws);
int		wint_len(wint_t *wc);
int		get_len_for_wchar(t_arg *arg_elem);
int		get_len_for_wint(t_arg *arg_elem);
int		put_wstr(t_arg *arg_elem);
int		put_wchar_with_prefix(t_arg *arg_elem, wchar_t **ws, int w_str_len);
int		wchar_len_for_precision(t_arg *arg_elem, wchar_t **ws);
int		octet_count_with_precision(t_arg *arg_elem, wchar_t **ws);
int		put_wchar_with_soustract(t_arg *arg_elem, wchar_t **ws, int w_str_len);
int		put_wchar_without_width(t_arg *arg_elem, wchar_t **ws, int w_str_len);
int		wint_size(t_arg *t_arg_elem, wchar_t wc);

/*
** %pf
*/
char	*get_arg_modified_for_p(t_arg *arg);
char	*f_to_str(t_arg *t_arg_elem, long double decimal, char *str_entier);
char	*apply_option_diese_to_f(t_arg *t_arg_elem, char *str_entier);
char	*apply_zero_space_to_f(t_arg *t_arg_elem, char *str, char *arg);
char	*apply_option_plus_to_f(t_arg *t_arg_elem, char *str, char *arg);
char	*apply_option_zero_to_f(t_arg *t_arg_elem, char *str, char *arg);
char	*apply_option_space_to_f(t_arg *t_arg_elem, char *str, char *arg);
int		get_arg_f(t_arg *arg_elem, va_list args);
char	*apply_option_to_f(t_arg *arg_elem, char *str, char *arg);
char	*get_arg_modified_for_f(t_arg *arg_elem);
char	*get_arg_modified_for_pourcent(t_arg *arg_elem);

/*
** Leaks Management
*/
void	clear_dioux(t_arg *arg_elem, t_dioux *dioux);
void	clear_all(t_arg *args_list);

#endif
