/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:40:39 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 21:05:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

# include "libft/libft.h"

char	*ft_utoa(unsigned int n);
void	ft_putnbr_base(int nbr, char *base);

int     has_format_specifiers(const char *str);
void	ft_putstr(const char *str);

int     ft_prints(char *str);
int	    ft_printc(int value);
int	    ft_printi(int value);
int		ft_printu(unsigned int value);
int     ft_printx(unsigned int value);
int     ft_printX(unsigned int value);

//int     ft_printp(unsigned char	*str);

int	ft_printf(const char *str, ...);


#endif