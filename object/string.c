#include "../includes/cube3D.h"

static void	string_destructor(t_string *str)
{
	str->lenght = 0;
	str->size = 0;
	if (str->str)
		free(str->str);
	str->str = NULL;
	}


static int32_t	alloc_string(t_string *str1, size_t lenght)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (str1->lenght + lenght + 20));
	if (!str)
		return (FAILURE);
	str1->size = str1->lenght + lenght + 20;
	while (str1->str && str1->str[i])
	{
		str[i] = str1->str[i];
		i++;
	}
	if (str1->str)
		free(str1->str);
	str1->str = str;
	return (SUCCESS);
}

static int32_t	append(t_string *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (!str2)
		return (SUCCESS);
	if ((ft_strlen(str2) + str1->lenght) >= str1->size)
		if (alloc_string(str1, ft_strlen(str2)) == FAILURE)
			return (FAILURE);
	while (str2[i])
		str1->str[(str1->lenght)++] = str2[i++];
	str1->str[str1->lenght] = '\0';
	return (SUCCESS);
}

static void	reference_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	copy->lenght = to_copy.lenght;
	copy->size = to_copy.size;
	copy->str = to_copy.str;
}

static int32_t	profond_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	if (copy->append(copy, to_copy.str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int64_t	find(t_string *str, const char *str2)
{
	int	i;
	const size_t str2_len = ft_strlen(str2);

	if (!str->str || !str2)
		return (-1);
	i = 0;
	while (i + str2_len < str->lenght)
	{
		if (ft_strncomp(&str->str[i], str2, str2_len) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int64_t	find_file_instructions(t_string str, char **lines, const char **find)
{
	int64_t	i;
	void	*addr;

	i = 0;
	addr = find;
	while (i < 6)
	{
		find = addr;
		if (*str.str != '\n')
			{
				while (ft_strncomp(str.str, *find, ft_strlen(*find)) && find++)
					if (!(*find))
						return (-1);
				if (lines[((void*)find - addr) / 8])
					return (-2);
				lines[((void*)find - addr) / 8] = str.str;
				while (*str.str != '\n')
					str.str++;
				i++;
			}
			str.str++;
	}
	return ((int64_t)str.str);
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
	str->find_file_instructions = find_file_instructions;
}
