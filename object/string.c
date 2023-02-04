#include "../includes/cube3D.h"

static void	string_destructor(t_string *str)
{
	str->lenght = 0;
	str->size = 0;
	if (str->str)
		free(str);
	str->str = NULL;
}


static int	alloc_string(t_string *str1, size_t lenght)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (str1->lenght + lenght + 20));
	if (!str)
		return (FAILURE);
	str1->size = str1->lenght + lenght + 20;
	str1->lenght = str1->lenght + lenght;
	while (str1->str[i])
	{
		str[i] = str1->str[i];
		i++;
	}
	while ((u_int64_t)i < str1->size)
	{
		str[i++] = 0;
	}
	if (str1->str)
		free(str1->str);
	str1->str = str;
	return (SUCCESS);
}

static int32_t	append(t_string *str1, const char *str2)
{
	int		i;

	i = 0;
	if (!str2)
		return (SUCCESS);
	if ((ft_strlen(str2) + str1->lenght) > str1->size)
		if (alloc_string(str1, ft_strlen(str2)) == FAILURE)
			return (FAILURE);
	while (str2[i])
	{
		str1->str[++(str1->lenght)] = str2[i];
		i++;
	}
	return (SUCCESS);
}

static void	reference_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	copy->lenght = to_copy.lenght;
	copy->size = to_copy.size;
	copy->str = to_copy.str;
}

static int	profond_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	if (copy->append(copy, to_copy.str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int find(t_string *str, const char *str2)
{
	int	i;
	const size_t str2_len = ft_strlen(str2);

	if (!str->str || str2)
		return (-1);
	i = 0;
	while (i + str2_len < str->lenght)
	{
		if (ft_strncomp(&str->str[i], str2, str2_len) == 0)
		{
			str->str = &str->str[i];
			str->lenght = str->lenght - i;
			str->size = str->size - i;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	string_init(t_string *str)
{
	str->str = NULL;
	str->size = 0;
	str->lenght = 0;
	str->append = append;
	str->alloc_string = alloc_string;
	str->string_destructor = string_destructor;
	str->reference_copy_operator = reference_copy_operator;
	str->profond_copy_operator = profond_copy_operator;
	str->find = find;
}