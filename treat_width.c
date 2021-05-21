#include "libft.h"

void	put_zero_and_space(t_list *flags, int num)
{
	while (flags->precision - num > 0)
    {
        if (flags->minus > 0 || flags->zero > 0)
            flags->count += ft_putchar_fd('0', 1);
        else
            flags->count += ft_putchar_fd(' ', 1);
        flags->precision--;
    }
}

void	treat_width(t_list *flags, int num)
{
    if (flags->minus > 0 && flags->precision > 0)
    {
        flags->minus = 0;
        put_zero_and_space(flags, num);
    }
    if (flags->precision > 0 && flags->dot > 0)
    {
        if (flags->negative)
            ft_putchar_fd('-', 1);
        put_zero_and_space(flags, flags->dot);
    }
    if (flags->dot > 0)
	{
	    flags->precision = flags->dot;
	    flags->minus = 1;
	    put_zero_and_space(flags, num);
	}
	if (flags->precision > 0)
		put_zero_and_space(flags, num);
}


int	num_div(int j)
{
	int num;
	int i;

	num = 0;
	i = j;
	if (i < 0)
		i *= -1;
	if (i >= 0 && i <= 9)
		num = 1;
	else
	{
		while (i > 0)
		{
			i /= 10;
			num++;
		}
	}
	return (num);
}

int dispars_num(t_list *flags, va_list argc, char *list, int i)
{
    if (list[i] == 'd' || list[i] == 'i')
        flags->num = va_arg(argc, int);
    else if (list[i] == 'u')
        flags->num = va_arg(argc, int);
    else if (list[i] == 'x' || list[i] == 'X')
    {
        flags->hex = va_arg(argc, long long);
			return (treat_hex(flags, list, i));
    }
    return (dispars_int(flags, argc));
}

int dispars_neg(t_list *flags)
{
    int num;

    num = num_div(flags->num);
    if(flags->dot && flags->minus == 0)
    {
        ft_putchar_fd('-', 1);
        treat_width(flags, num);
        ft_putnbr_fd(flags->num *= -1, 1);
        num++;
    }
    else
    {
        treat_width(flags, ++num);
        ft_putchar_fd('-', 1);
        ft_putnbr_fd(flags->num *= -1, 1);
    }
    return (num);
}

int dispars_int(t_list *flags, va_list argc)
{
	int num;

	num = num_div(flags->num);
	if (flags->num < 0)
	    flags->negative = 1;
    if (flags->negative && flags->zero == 1)
    {
        num += ft_putchar_fd('-', 1);
        treat_width(flags, num);
        ft_putnbr_fd(flags->num *= -1, 1);
    }
    else if (flags->negative && flags->minus > 0)
    {
        num += ft_putchar_fd('-', 1);
        ft_putnbr_fd(flags->num *= -1, 1);
        treat_width(flags, num);
    }
    else if (flags->negative)
       return (dispars_neg(flags));
	else
	{
        if (flags->minus == 1)
        {
            ft_putnbr_fd(flags->num, 1);
            treat_width(flags, num);
        }
        else
        {
            treat_width(flags, num);
            ft_putnbr_fd(flags->num, 1);
        }
	}
    return (num);
}
