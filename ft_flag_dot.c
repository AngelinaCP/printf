#include "libft.h"

int	ft_flag_dot(char *list, int i, t_list *flags, va_list argc)
{
	flags->dot = 1;
	if (list[i++] == '*')
		flags->dot = 1;
	return (flags ->dot);
}

int	ft_flag_zero(char *list, int i, t_list *flags, va_list argc)
{
	flags->zero = 1;
	return (flags->zero);
}

int	ft_flag_minus(t_list *flags)
{
	flags->minus = 1;
	return (flags->minus);
}

int	ft_flag_star(char *list, int i, t_list  *flags, va_list argc)
{
	flags ->star = 1;
	if (list[++i] == '.')
		flags->star = 0;
		flags->width = va_arg(argc, int);
	if (flags->width > 0)
		return (flags ->width);
	else
	{
		flags->minus = 1;
		flags->width *= (-1);
	}
	return (flags ->width);
}

int    ft_is_flag(char *list, int i, t_list *flags, va_list argc)
{
    int count;

    count = 0;

    count += ft_flag_pars(list, i, flags, argc);
    return (count);
}

int	ft_digit_pars(char *list, int i, t_list *flags, va_list argc)
{   
	flags->width = 0;
	if (flags ->star == 1)
		return (flags->width);
	while (ft_isdigit(list[i]))
	{
		flags->width = (flags->width * 10) + (list[i] - '0');
		++i;
	}
    if (flags->dot == 1)
        flags->dot = flags->width;
    else
        flags->precision = flags->width;
	return (flags ->width);
}
