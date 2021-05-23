#include "libft.h"

int dispars_num(t_list *flags, va_list argc, char *list, int i)
{
    if (list[i] == 'd' || list[i] == 'i')
	{
		flags->num = va_arg(argc, int);
		flags->base = 10;
	}
    else if (list[i] == 'x' || list[i] == 'X')
    {
        flags->num = va_arg(argc, long long);
        flags->base = 16;
    }
    else if (list[i] == 'u')
	{
		flags->num = va_arg(argc, unsigned int);
		flags->base = 10;
	}
    else if(list[i] == 'p')
	{
		flags->num = va_arg(argc, long long);
		flags->base = 16;
		flags->precision -= 2;
	}
    return (treat_int(flags, list, i));
}

int treat_pointer(t_list *flags, int num, char *list, int i)
{
	int count;

	count = ft_putstr_fd("0x", 0, 0);
	//if (flags->dot == 1 && flags->width == flags->precision)
		count += putnb_short_base(flags->num, flags->base, flags->low_hex, flags);
	return (count);
}

int treat_int(t_list *flags, char *list, int i)
{
	int num;

	num = num_div(flags->num, flags->base);
	if (list[i] == 'p')
		num += 2;
	if (get_null(flags))
		return (0);
	if (flags->num < 0)
	{
		flags->sym = '-';
		flags->dot++;
		num++;
	}
	if (flags->minus == 0)
		return (dispars_int(flags, num, list, i));
	else
		return (dispars_neg(flags, num, list, i));
}

int dispars_int(t_list *flags, int num, char *list, int i)
{
	if (flags->zero == 1 && flags->precision > 0 && flags->dot <= 1)
		flags->dot = flags->precision;
	if (flags->precision == 0 || flags->precision < flags->dot)
		flags->precision = flags->dot;
	if (flags->precision > flags->dot && flags->dot != 0)
	{
		if (flags->dot > num)
			put_zero_and_space(flags, flags->dot);
		else
			put_zero_and_space(flags, num);
	}
	else
		put_zero_and_space(flags, flags->dot + num);
	if (flags->sym)
		ft_putchar_fd(flags->sym, 1);
	if (flags->dot > 0)
	{
		flags->minus = 1;
		if (flags->dot > num && flags->dot != flags->precision)
			put_zero_and_space(flags, flags->dot);
		else
			put_zero_and_space(flags, num);
	}
	num = int_disp(list, i, flags, num);
	return (num);
}


int dispars_neg(t_list *flags, int num, char *list, int i)
{
	if (flags->num < 0)
		ft_putchar_fd('-', 1);
	if (flags->precision == 0 || flags->precision < flags->dot)
		flags->precision = flags->dot;
	if (flags->dot > 0)
	{
		flags->minus = 1;
		if (flags->dot > num)
			put_zero_and_space(flags, flags->precision - (flags->dot - num));
		else if (flags->dot > num)
			put_zero_and_space(flags, num);
	}
	int_disp(list, i, flags, num);
	flags->minus = 0;
	if (flags->dot > 0)
		put_zero_and_space(flags, num);
	else
		put_zero_and_space(flags, num);
	return (num);

}
