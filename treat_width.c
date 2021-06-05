#include "libft.h"

int	dispars_num(t_list *flags, va_list argc, char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
	{
		flags->num = va_arg(argc, int);
		flags->base = 10;
	}
	else if (format[i] == 'x' || format[i] == 'X')
	{
		flags->num = va_arg(argc, unsigned int);
		flags->base = 16;
	}
	else if (format[i] == 'p')
	{
		flags->num = va_arg(argc, long long);
		flags->base = 16;
	}
	else if (format[i] == 'u')
	{
		flags->num = va_arg(argc, unsigned int);
		flags->base = 10;
	}
	return (treat_int(flags, format, i));
}

int	treat_pointer(t_list *flags)
{
	int	count;

	count = 2;
	if ((flags->dot > 0 && flags->num != 0) || flags->dot_p >= 0)
		if (flags->dot_p != 1)
			count += putnb_short_base(flags->num,
					flags->base, flags->low_hex, flags);
	return (count);
}

int	int_condition(t_list *flags, int num, char *format, int i)
{
	if (format[i] == 'p')
	{
		num += 2;
		if (flags->dot_p)
			num--;
		flags->sym = "0x";
	}
	if (flags->num < 0)
		flags->sym = "-";
	if (flags->precision < 0)
	{
		flags->precision *= -1;
		flags->minus = 1;
	}
	return (num);
}
