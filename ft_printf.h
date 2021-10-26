/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:53:30 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/25 13:39:38 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "libft/libft.h"

enum e_printf_flags {
	PRINTF_FLAG_NONE=0b00000,
	PRINTF_FLAG_ALTR=0b00001,
	PRINTF_FLAG_PLUS=0b00010,
	PRINTF_FLAG_SPAC=0b00100,
	PRINTF_FLAG_LEFT=0b01000,
	PRINTF_FLAG_ZERO=0b10000
};

typedef struct s_printf_opt {
	int					width;
	int					length;
	enum e_printf_flags	flags;
}	t_printf_opt;

int	ft_printf(const char *s, ...);
int	ft_printf_uint(char *bef, unsigned int n, t_printf_opt *opt);
int	ft_printf_int(int nb, t_printf_opt *opt);
int	ft_printf_char(char c, t_printf_opt *opt);
int	ft_printf_str(char *s, t_printf_opt *opt);
int	ft_printf_base16(unsigned long n, char *base, t_printf_opt *opt);
int	ft_printf_ptr(unsigned long long n, char *base, t_printf_opt *opt);

int	ft_printf_n(char *bef, char *str, int n, t_printf_opt *opt);
int	ft_printf_s(char *str, int n, t_printf_opt *opt);

#endif
