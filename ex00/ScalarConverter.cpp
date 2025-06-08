/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:34 by athonda           #+#    #+#             */
/*   Updated: 2025/06/08 20:37:28 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>		// isdigit
#include <string>		// string
#include <iostream>		// std::cout
#include <iterator>		// istream_iterator
#include "ScalarConverter.hpp"

int		ScalarConverter::checkChar(std::string const &s)
{
	if (s.length() == 1 && !isdigit(s[0]))
		return (1);
	return (0);
}

int		ScalarConverter::checkInt(std::string const &s)
{
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		if (!isdigit(*it))
			return (0);
	}
	return (1);
}

int	ScalarConverter::checkFloat(std::string const &s)
{
	if (*(s.end() - 1) != 'f')
		return (0);
	size_t pos = -1;
	if ((pos = s.find('.', 0)) != std::string::npos)
	{
		size_t pos2 = 0;
		if ((pos2 = s.find('.', pos + 1)) != std::string::npos)
		{
			std::cout << "double dots" <<std::endl;
			return (0);
		}
	}
	for (size_t i = 0; i < s.length() - 1; ++i)
	{
		if (i != pos && !isdigit(s[i]))
			return (0);
	}
	return (1);
}

int	ScalarConverter::checkDouble(std::string const &s)
{
	std::string	const &dot = ".";
	size_t	pos = 0;
	size_t	pos2 = 0;
	if((pos = s.find(dot, pos)) == std::string::npos)
		return (0);
	if ((pos2 = s.find(dot, pos + 1)) != std::string::npos)
	{
		std::cout << "double pos" <<std::endl;
		return (0);
	}
	else
	{
		std::string::const_iterator dotpos = s.begin() + pos;
		for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
		{
			if (it != dotpos && !isdigit(*it))
				return (0);
		}
		return (1);
	}
}

e_ScalarType		ScalarConverter::checkType(std::string const &s)
{
	if (checkChar(s))
		return (TYPE_CHAR);
	else if (checkInt(s))
		return (TYPE_INT);
	else if (checkDouble(s))
		return (TYPE_FLOAT);
	else if (checkFloat(s))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

void	ScalarConverter::convert(std::string const &input)
{
	std::cout << input << std::endl;
	e_ScalarType	type = checkType(input);

	switch(type)
	{
		case 0:
			std::cout << type << std::endl;
			break ;
		case 1:
			std::cout << type << std::endl;
			break ;
		case 2:
			std::cout << type << std::endl;
			break ;
		case 3:
			std::cout << type << std::endl;
			break ;
		case 4:
			std::cout << type << std::endl;
			break ;
	}

}