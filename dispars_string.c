#include "libft.h"

int string_precision(t_list *flags, va_list argc)
{
    int i;
    char	*ar;

    ar = va_arg(argc, char *);

    i = flags->width;
    if (flags->width > 0)
    {
        put_zero_and_space(flags, ft_strlen(ar));
        flags->count += ft_putstr_fd(ar, i, 1);
    }
    else
        flags->count += ft_putstr_fd(ar, i, 1);
    return (flags->count);
}

int dispars_string(t_list *flags, va_list argc, char *list, int i)
{
	int		len;
	char	*ar;

	len = 0;
	ar = va_arg(argc, char *);
	if (ar == NULL)
	    len += ft_putstr_fd("(null)", 0, 1);
	if (flags->dot < flags->precision)
	    flags->dot = ft_strlen(ar);
	//printf("%d", flags->precision);
    if (flags->minus == 1)
    {
        len += ft_putstr_fd(ar, 0,  1);
        put_zero_and_space(flags, ft_strlen(ar));
    }
    else if (flags->precision > 0)
    {
        put_zero_and_space(flags, ft_strlen(ar));
        len += ft_putstr_fd(ar, flags->dot, 1);
    }
    else
        len += ft_putstr_fd(ar, flags->dot,1);
	return (len);
}
