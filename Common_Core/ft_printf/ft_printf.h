/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:40:39 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 03:03:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

# include "libft/libft.h"

int	has_format_specifiers(const char *str);
void	ft_putstr(const char *str);
void    ft_prints(char	*str);
void	ft_printc(int value);

int	ft_printf(const char *str, ...);


#endif