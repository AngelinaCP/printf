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
	int	i, c, num;

	num = 0;
	i = 0;
	c = 0;
    ft_flags_s(flags);
	while (list[i])
	{
		i = check_space(i, list, argc, flags);
		if (list[i])
		{
			c += ft_putchar_fd(list[i], 1);
			i++;
		}
	}
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
//	int i = 15;
//	char *s = "privet";
//	ft_printf("%.*p", -1, 0);
//	printf("\n");
//	printf("%.*p", -1, 0);
//}
