#include "ft_printf.h"
#include "color_code.h"

void	ft_color(const char **format)
{
	int		i;
	int		j;
	char	*code;

	if (**format != '{')
		return ;
	i = 0;
	while ((*format)[i] && (*format)[i] != '}')
		i++;
	if (!(*format)[i] || i == 0)
		return ;
	code = ft_strsub(*format, 1, i - 1);
	j = 0;
	while (!ft_strequ(code, color_table[j].code) && !ft_strequ("", color_table[j].code))
		j++;
	if (ft_strequ("", color_table[j].code))
		return ;
	ft_putstr(color_table[j].ansi);
	*format += i + 1;
	ft_strdel(&code);
}
