/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:06:11 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:06:13 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ZERO_OR_SPACE " 0"

# define ZNAK "-+ "

# define LOW_HEX "0123456789abcdef"
# define UPP_HEX "0123456789ABCDEF"
# define DECIMAL "0123456789"

# define FLAGS "0123456789. -+#"
# define FLAGS_COUNT 15

# define MAX_INT 2147483647

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags {
	int	precision;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	minus;
	int	zero;
}	t_flags;

int		ft_printf(const char *fmt, ...);

void	add_width(char *symbol, int width, int piece_len);
int		ft_strlen(char *s);
void	get_flags(t_flags *flags, const char *fmt_piece, int last_index);
int		get_num_len(unsigned long long p, int fundament);
void	iputnbr(long long p, int fundament, char *alphabet);
int		is_flag(char c);
void	uputnbr(unsigned long long p, int fundament, char *alphabet);
char	*zn(long long d, t_flags flags);

int		c_check(unsigned char c, const char *fmt_piece,
			int last_index, int *full_len);
int		c_print(int c, const char *fmt_piece, int last_index);
int		d_check(int d, const char *fmt_piece, int last_index, int *full_len);
int		d_print(int d, const char *fmt_piece, int last_index);
int		p_check(unsigned long long p, const char *fmt_piece,
			int last_index, int *full_len);
int		p_print(unsigned long long p, const char *fmt_piece, int last_index);
int		s_check(char *s, const char *fmt_piece, int last_index, int *full_len);
int		s_print(char *s, const char *fmt_piece, int last_index);
int		u_check(unsigned int u, const char *fmt_piece,
			int last_index, int *full_len);
int		u_print(unsigned int u, const char *fmt_piece, int last_index);
int		x_check(unsigned int x, const char *fmt_piece,
			int last_index, int *full_len);
int		x_print(unsigned int x, const char *fmt_piece, int last_index);
int		xx_print(unsigned int x, const char *fmt_piece, int last_index);

#endif
