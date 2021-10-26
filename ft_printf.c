/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:55:41 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/25 13:38:40 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_opt	ft_printf_init_opt(void)
{
	t_printf_opt	opt;

	opt.flags = PRINTF_FLAG_NONE;
	opt.width = 0;
	opt.length = -1;
	return (opt);
}

t_printf_opt	ft_printf_parse_opt(const char **s)
{
	t_printf_opt	opt;

	opt = ft_printf_init_opt();
	while (1)
	{
		if (**s == '#')
			opt.flags |= PRINTF_FLAG_ALTR;
		else if (**s == '+')
			opt.flags |= PRINTF_FLAG_PLUS;
		else if (**s == ' ')
			opt.flags |= PRINTF_FLAG_SPAC;
		else if (**s == '-')
			opt.flags |= PRINTF_FLAG_LEFT;
		else if (**s == '0')
			opt.flags |= PRINTF_FLAG_ZERO;
		else
			break ;
		(*s)++;
	}
	while (ft_isdigit(**s))
		opt.width = opt.width * 10 + *(*s)++ - '0';
	if (**s == '.' && (*s)++ && opt.length++)
		while (ft_isdigit(**s))
			opt.length = opt.length * 10 + *(*s)++ - '0';
	return (opt);
}

int	ft_printf_parse(const char **s, va_list *args)
{
	t_printf_opt	opt;

	opt = FT_PRINTF_PARSE(s);
	if (**s == '%')
		return (write(1, "%", 1));
	else if (**s == 'c')
		return (ft_printf_char(va_arg(*args, int), &opt));
	else if (**s == 's')
		return (ft_printf_str(va_arg(*args, char *), &opt));
	else if (**s == 'd' || **s == 'i')
		return (ft_printf_int(va_arg(*args, int), &opt));
	else if (**s == 'u')
		return (ft_printf_uint(NULL, va_arg(*args, unsigned int), &opt));
	else if (**s == 'x')
		return (ft_printf_base16(va_arg(*args, unsigned int),
				"0123456789abcdef0x", &opt));
	else if (**s == 'X')
		return (ft_printf_base16(va_arg(*args, unsigned int),
				"0123456789ABCDEF0X", &opt));
	else if (**s == 'p')
		return (ft_printf_ptr(va_arg(*args, unsigned long long),
				"0123456789abcdef", &opt));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s++ != '%')
			i++;
		else
		{
			len += write(1, s - i - 1, i);
			i = 0;
			len += ft_printf_parse(&s, &args);
			s++;
		}
	}
	len += write(1, s - i, i);
	va_end(args);
	return (len);
}
