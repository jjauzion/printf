#include "ft_printf.h"
#include "color_code.h"

int		ft_color(const char **str)
{
	int		i;
	int		j;
	char	*code;

	if (**str != '{')
		return (0);
	i = 0;
	while ((*str)[i] && (*str)[i] != '}')
		i++;
	if (!(*str)[i] || i == 0)
		return (0);
	code = ft_strsub(*str, 1, i - 1);
	j = 0;
	while (!ft_strequ(code, color_table[j].code) && !ft_strequ("", color_table[j].code))
		j++;
	if (ft_strequ("", color_table[j].code))
		return (0);
	ft_putstr(color_table[j].ansi);
	*str += i + 1;
	ft_strdel(&code);
	return (1);
}
