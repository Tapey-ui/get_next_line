/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/10/24 17:59:00 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRNTF_H

#include <unistd.h>
#include <stdargs.h>

typedef struct  s_format
{
    int     width;
    int     prec;
    int     plus;
    int     minus;
    int     space;
    int     zero;
    int     hash;
    int     dot;
    int     sign;
    char    type;
}   t_format;

#endif