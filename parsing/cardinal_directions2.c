
#include "parsing.h"

int	ft_int_dup(char *str, int num)
{
	char	*tmp;
	char	*res;
	char	**spl;
	int		i;

	tmp = ft_dup(str);
	rgb_parse(tmp);
	printf("tmp == [%s]\n", tmp);
	res = ft_strdup("\0");
	// tmp = ft_atoi(num);
	spl = ft_split(tmp, ',');
	i = 0;
	while (spl[i])
	{
		res = ft_strjoin(res, spl[i]);
		if (ft_atoi(spl[i]) >= 255)
			put_error("INVALID RGB");
		i++;
	}
	if (i != 3)
		put_error("INVALID RGB");
	if (num < 0)//// protections
		num = 0;
	ft_free(spl);
	return (ft_atoi(res));
}
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

void	ea_and_colors1(char **str, t_directions *dir, int *s, int i)
{
    if (!ft_strcmp(str[0], "EA") && str_lenght(str) == 2)
	{
		if (dir->ea)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->ea = ft_dup(str[1]);
	}
	else if (!ft_strcmp(str[0], "F") && str_lenght(str) == 2)
	{
		if (dir->f != -1)
			put_error("TOO MANY F COLORS");////F ??
		dir->f = ft_int_dup(str[1], dir->f);//// protect numb
	}
	else if (!ft_strcmp(str[0], "C") && str_lenght(str) == 2)
	{
		if (dir->c != -1)////repars it
			put_error("TOO MANY C COLORS");////C ??
		dir->c = ft_int_dup(str[1], dir->f);//// protect numb
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

int	ea_and_colors(char *str, t_directions *dir, int *s, int i)
{
	(void)i;
    if (!ft_strcmp(str, "EA"))
	{
		if (dir->ea)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		return (EA);
	}
	else if (!ft_strcmp(str, "F"))
	{
		if (dir->f != -1)
			put_error("TOO MANY F COLORS");////F ??
		return (F);//// protect numb
	}
	else if (!ft_strcmp(str, "C"))
	{
		if (dir->c != -1)////repars it
			put_error("TOO MANY C COLORS");////C ??
		return (C);//// protect numb
	}
	else if (!*s && skipp_spaces(str, '1'))
	{
		check_cardinal(dir);
		*s = i;
	}
	else if (!ft_strcmp(str, ";"))
		return (-2);
	else if (!skipp_spaces(str, '1'))
	{
		printf("[%s]\n", str);
		put_error("MAP NOT VALID");
	}
	return (-2);
}

void	fill_struct(t_directions **dir, char *crdl, int index)
{
	if (!crdl || !*crdl)
		return;
	if (index == NO)
	{
		(*dir)->no = ft_dup(crdl);
		printf("NO = %s\n", (*dir)->no);
		// exit(1);
	}
	else if (index == SO)
	{
		(*dir)->so = ft_dup(crdl);
		printf("SO = %s\n", (*dir)->so);
	}
	else if (index == WE)
	{
		(*dir)->we = ft_dup(crdl);
		printf("WE = %s\n", (*dir)->we);
	}
	else if (index == EA)
	{
		(*dir)->ea = ft_dup(crdl);
		printf("EA = %s\n", (*dir)->ea);
	}
	else if (index == F)
	{
		(*dir)->f = ft_int_dup(crdl, (*dir)->f);
		printf("F = %d\n", (*dir)->f);
	}
	else if (index == C)
	{
		(*dir)->c = ft_int_dup(crdl, (*dir)->c);
		printf("C = %d\n", (*dir)->c);
	}
}
