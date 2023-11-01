/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:52:27 by giorgia           #+#    #+#             */
/*   Updated: 2023/11/01 16:54:21 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_base(unsigned int n, char *base);
int	ft_pointer(unsigned long n);
int	ft_printf(const char *str, ...);
int	ft_strcmp(char *s1, char *s2);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);

#endif
