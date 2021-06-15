#include "libftprintf.h"

int	ft_flags_count(t_list *flags, char *format, int i)
{
	if (format[i] == '.')
		flags->dot_p = 1;
	else if (format[i] == '0')
		flags->zero = 1;
	else if (format[i] == '-')
		flags->minus = 1;
	return (1);
}

static void	star_neg(t_list *flags)
{
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= (-1);
	}
	flags->precision = flags->width;
	flags->width = 0;
}

int	ft_flag_star(t_list *flags, va_list argc)
{
	flags->star = 1;
	flags->width = va_arg(argc, int);
	if (flags->dot_p == 1)
	{
		if (flags->width < 0)
		{
			flags->dot = -1;
			return (flags->width);
		}
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= (-1);
		}
		flags->dot = flags->width;
		flags->width = 0;
	}
	else
		star_neg(flags);
	return (1);
}

int	ft_is_flag(char *format, int i, t_list *flags, va_list argc)
{
	int	count;

	count = ft_flag_pars(format, i, flags, argc);
	return (count);
}

int	ft_digit_pars(char *format, int i, t_list *flags)
{
	while (ft_isdigit(format[i]))
	{
		flags->width = (flags->width * 10) + (format[i] - '0');
		++i;
	}
	if (flags->dot_p == 1)
	{
		flags->dot = flags->width;
		flags->width = 0;
	}
	else
	{
		flags->precision = flags->width;
		flags->width = 0;
	}
	return (flags ->width);
}
