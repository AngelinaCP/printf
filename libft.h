/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:47:33 by ddelena           #+#    #+#             */
/*   Updated: 2021/05/03 20:08:23 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	int	width;
	int	dot;
	int	minus;
	int	star;
	int	zero;
	int space;
	int count;
	int precision;
	int num;
	int negative;
	long long hex;
	char *hexid;
}	t_list;


int		ft_flags(char c);
int		ft_conversion(char c);
int		ft_isalpha(int s);
int		ft_isdigit(int s);
int	    ft_putchar_fd(char s, int fd);
int	    ft_putstr_fd(char *s, int j, int fd);
void	ft_putendl_fd(char *s, int fd);
int	    ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *, ...);
char	*ft_strdup(const char *s1);
int     ft_flag_dot(char *list, int i, t_list *flags, va_list argc);
int	    ft_atoi(const char *str);
int     ft_flag_zero(char *list, int i, t_list *flags, va_list argc);
int     ft_flag_minus(t_list *flags);
int ft_flag_star(char *list, int i, t_list  *flags, va_list argc);
int ft_flag_pars(char *list, int i, t_list *flags, va_list argc);
size_t	ft_strlen(const char *str);
int	ft_type_pars(char *list, int i, t_list *flags, va_list argc);
int ft_is_flag(char *list, int i, t_list *flags, va_list argc);
int ft_digit_pars(char *list, int i, t_list *flags, va_list argc);
void ft_flags_s(t_list *flags);
int     ft_flags(char c);
int     ft_conversion (char c);
int dispars_int(t_list *flags, va_list argc);
void treat_width(t_list *flags, int num);
int dispars_char(t_list flags, va_list argc, char *list, int i);
int	ft_check_flags(va_list argc, char *list, t_list *flags);
void char_minus(t_list flags, va_list argc, int ar);
void put_zero_and_space(t_list *flags, int num);
int dispars_string(t_list *flags, va_list argc, char *list, int i);
void ft_isspace(t_list *flags, va_list argc);
int check_space(int i, char *list, va_list argc, t_list *flags);
void    print_percent(t_list *flags);
int string_precision(t_list *flags, va_list argc);
int dispars_num(t_list *flags, va_list argc, char *list, int i);
int dispars_neg(t_list *flags);
int putnb_short_base(long long n, size_t base_len, char *base);

#endif
