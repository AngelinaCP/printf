#include "libftprintf.h"

int	ft_flag_pars(char *format, int i, t_list *flags, va_list argc)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		 dispars_char(flags, argc);
	else if (format[i] == 'i' || format[i] == 'd')
		count = dispars_num(flags, argc, format, i);
	else if (format[i] == 'u')
		count = dispars_num(flags, argc, format, i);
	else if (format[i] == 's')
	{
		if (flags->dot_p == 1 && flags->dot == 0)
			flags->dot_e = 1;
		count = dispars_string(flags, argc);
	}
	else if (format[i] == 'x' || format[i] == 'X')
		count = dispars_num(flags, argc, format, i);
	else if (format[i] == 'p')
		count = dispars_num(flags, argc, format, i);
	return (count);
}
