#include "libftprintf.h"

int	ft_type_pars(char *format, int i, t_list *flags, va_list argc)
{
	while (ft_isdigit(format[i]) || ft_conversion(format[i])
		|| ft_flags(format[i]))
	{
		if (format[i] == '%')
		{
			print_percent(flags);
			i++;
			break ;
		}
		i = format_pars_flags(format, i, flags, argc);
		if (ft_isdigit(format[i]))
			i = format_pars_digit(format, i, flags);
		else if (ft_flags(format[i]))
		{
			flags->count += ft_is_flag(format, i, flags, argc);
			i++;
			break ;
		}
		else
			return (-1);
	}
	return (i);
}

int	format_pars_digit(char *format, int i, t_list *flags)
{
	ft_digit_pars(format, i, flags);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

int	format_pars_flags(char *format, int i, t_list *flags, va_list argc)
{
	while (ft_conversion(format[i]))
	{
		if (format[i] == '*')
		{
			ft_flag_star(flags, argc);
			i++;
		}
		else if (format[i] == '.' || format[i] == '0' || format[i] == '-' )
			i += ft_flags_count(flags, format, i);
	}
	return (i);
}
