#include "libft.h"

int	check_space(int i, char *list, va_list argc, t_list *flags)
{
	int catch, space;

	catch = 0;
	space = 0;
	if (list[i] == '%')
	{
		i++;
		catch = 1;
	}
	while (catch)
	{
		ft_flags_s(flags);
		while (list[i] == ' '  && (space = 1))
            i++;
		if (space)
		{
			ft_putchar_fd(' ', 1);
			space = 0;
		}
		catch = 0;
		if ((i = ft_type_pars(list, i, flags, argc)) == -1)
			return (-1);
        if (list[i] == '%')
        {
            i++;
            catch = 1;
        }
	}
	return (i);
}

int	ft_check_flags(va_list argc, char *list, t_list *flags)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	flags->count = 0;
	while (list[i])
	{
		i = check_space(i, list, argc, flags);
		if (list[i])
		{
			c += ft_putchar_fd(list[i], 1);
			i++;
		}
	}
	//printf("%d", flags->count);
	//printf("|%d|", c);
	return (flags->count + c);
}

int	ft_printf(const char *format, ...)
{
	char    *list;
	int     i;
	t_list  flags;
    va_list argc;
    list = ft_strdup(format);
	va_start(argc, format);
	i = ft_check_flags(argc, list, &flags);
	va_end(argc);
	//printf("|%i|", i);
	return (i);
}

//int main(void)
//{
//	int a = 1234;
//	int i = 0;
//	ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
//	printf("\n");
//	printf("\n%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
//}
