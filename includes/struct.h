/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:26:56 by asouat            #+#    #+#             */
/*   Updated: 2019/04/27 14:56:32 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct				s_dioux
{
	short int				*h_nb;
	unsigned short int		*h_unb;
	char					*hh_nb;
	unsigned char			*hh_unb;
	long int				*l_nb;
	unsigned long int		*l_unb;
	long long int			*ll_nb;
	unsigned long long int	*ll_unb;
	int						*nb;
	unsigned int			*unb;
}							t_dioux;

typedef struct				s_option
{
	int	plus;
	int	soustract;
	int	diese;
	int	zero;
	int	space;
}							t_option;

typedef struct				s_arg
{
	char			*settings;
	char			type;
	char			has_options;
	t_option		options;
	int				width_min;
	int				precision;
	char			*flag;
	void			*arg;
	char			*prefix;
	char			*arg_modified;
	struct s_arg	*next;
}							t_arg;

#endif
