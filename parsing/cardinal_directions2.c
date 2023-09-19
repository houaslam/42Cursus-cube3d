
#include "parsing.h"

int	skipp_spaces(char *str, char to_find)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == to_find)
		return (1);
	if (!str[i])
		return (-1);
	return (0);
}

void	ea_and_colors(char **str, t_directions *dir, int *s, int i)
{
    if (!ft_strcmp(str[0], "EA") && str_lenght(str) == 2)
	{
		if (dir->ea)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->ea = ft_strdup(str[1]);
	}
	else if (!ft_strcmp(str[0], "F") && str_lenght(str) == 2)
	{
		if (dir->f)
			put_error("TOO MANY F COLORS");////F ??
		dir->f = ft_strdup(str[1]);//// protect numb
	}
	else if (!ft_strcmp(str[0], "C") && str_lenght(str) == 2)
	{
		if (dir->c)////repars it
			put_error("TOO MANY C COLORS");////C ??
		dir->c = ft_strdup(str[1]);//// protect numb
	}
	else if (!*s && (skipp_spaces(str[0], '1') || \
		(skipp_spaces(str[0], '1') == -1 && skipp_spaces(str[1], '1'))))////not always the first we can find tabs
	{
		check_cardinal(dir);
		*s = i;
	}
	else if (!ft_strcmp(str[0], ";") && str_lenght(str) == 1)
		return ;
	else if (!skipp_spaces(str[0], '1'))
		put_error("MAP NOT VALID");
}
