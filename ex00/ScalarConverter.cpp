/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:34 by athonda           #+#    #+#             */
/*   Updated: 2025/06/10 21:43:41 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>			// fixed
#include <iomanip>		// setprecision
#include <cctype>		// isdigit
#include <string>		// string
#include <iostream>		// std::cout
#include <iterator>		// istream_iterator
#include "ScalarConverter.hpp"


int	ScalarConverter::checkFloatSymbol(std::string const &s)
{
	if (!s.compare("inff") || !s.compare("+inff") || !s.compare("-inff") || \
		!s.compare("nanf") || !s.compare("+nanf") || !s.compare("-nanf"))
	{
		return (1);
	}
	return (0);
}

int	ScalarConverter::checkDoubleSymbol(std::string const &s)
{
	if (!s.compare("inf") || !s.compare("+inf") || !s.compare("-inf") || \
		!s.compare("nan") || !s.compare("+nan") || !s.compare("-nan"))
	{
		return (1);
	}
	return (0);
}

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
	if (checkFloatSymbol(s))
		return (TYPE_FLOAT_SYMBOL);
	else if (checkDoubleSymbol(s))
		return (TYPE_DOUBLE_SYMBOL);
	else if (checkChar(s))
		return (TYPE_CHAR);
	else if (checkInt(s))
		return (TYPE_INT);
	else if (checkFloat(s))
		return (TYPE_FLOAT);
	else if (checkDouble(s))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

void	ScalarConverter::convertFloatSymbol(std::string const &s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (s[0] == '+')
		std::cout << "float: " << s.substr(1) << std::endl;
	else
		std::cout << "float: " << s << std::endl;
	if (s.find("inff", 0) != s.npos)
	{
		if (s[0] == '-')
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: inf" << std::endl;
	}
	else
	{
		if (s[0] == '-')
			std::cout << "double: -nan" << std::endl;
		else
			std::cout << "double: nan" << std::endl;
	}
}

void	ScalarConverter::convertDoubleSymbol(std::string const &s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (s.find("inf", 0) != s.npos)
	{
		if (s[0] == '-')
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: inff" << std::endl;
	}
	else
	{
		if (s[0] == '-')
			std::cout << "float: -nanf" << std::endl;
		else
			std::cout << "float: nanf" << std::endl;
	}
	if (s[0] == '+')
		std::cout << "double: " << s.substr(1) << std::endl;
	else
		std::cout << "double: " << s << std::endl;

}

void	ScalarConverter::convertChar(std::string s)
{
	std::cout << s << std::endl;
	std::cout << static_cast<int>(s[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << static_cast<double>(s[0]) << std::endl;
}

void	ScalarConverter::convert(std::string const &input)
{
	e_ScalarType	type = checkType(input);

	switch(type)
	{
		case TYPE_FLOAT_SYMBOL:
			convertFloatSymbol(input);
			break ;
		case TYPE_DOUBLE_SYMBOL:
			convertDoubleSymbol(input);
			break ;
		case TYPE_CHAR:
			convertChar(input);
			break ;
		case TYPE_INT:
			std::cout << type << std::endl;
			break ;
		case TYPE_FLOAT:
			std::cout << type << std::endl;
			break ;
		case TYPE_DOUBLE:
			std::cout << type << std::endl;
			break ;
		case TYPE_INVALID:
			std::cout << type << std::endl;
			break ;
	}

}