#include "libft.h"

int putnb_short_base(long long n, size_t base_len, char *base)
{
    if (n < base_len)
        return (ft_putchar_fd(base[n], 1));
    return (putnb_short_base(n / base_len, base_len, base) + ft_putchar_fd(n % base_len, 1));
}

