/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:04:42 by akassous          #+#    #+#             */
/*   Updated: 2024/07/02 12:43:23 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

void	space_saver(char *str, int i, int first)
{
	while (str[i] != '\0')
	{
		if (!is_alphanumeric(str[i]))
			first = 1;
		else
		{
			if (first == 1)
			{
				if (is_alphanumeric(str[i]))
					first = 0;
				if (str[i] >= 'a' && str[i] <= 'z')
						str[i] = str[i] - 32;
			}
			else
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] = str[i] + 32;
			}
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	space_saver(str, i, first);
	return (str);
}
