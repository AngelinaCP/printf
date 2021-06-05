#include "libft.h"

int	check_space(int i, char *format, va_list argc, t_list *flags)
{
	int	catch;

	catch = 0;
	if (format[i] == '%')
	{
		i++;
		catch = 1;
	}
	while (catch)
	{
		ft_flags_s(flags);
		while (format[i] == ' ')
			i++;
		catch = 0;
		i = ft_type_pars(format, i, flags, argc);
		if (i == -1)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			catch = 1;
		}
	}
	return (i);
}

int	ft_check_flags(va_list argc, char *format, t_list *flags)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	flags->count = 0;
	while (format[i])
	{
		i = check_space(i, format, argc, flags);
		if (format[i])
		{
			c += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	return (flags->count + c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_list	flags;
	va_list	argc;

	va_start(argc, format);
	i = ft_check_flags(argc, (char *)format, &flags);
	va_end(argc);
	return (i);
}
