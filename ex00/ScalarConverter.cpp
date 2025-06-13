/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:34 by athonda           #+#    #+#             */
/*   Updated: 2025/06/13 18:39:11 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>			// fixed
#include <iomanip>		// setprecision
#include <cctype>		// isdigit
#include <string>		// string
#include <iostream>		// std::cout
#include <iterator>		// istream_iterator
#include <cstdlib>		// atof, strtod
#include <limits>		// INT_MAX
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


int	ScalarConverter::checkFloat(std::string const &s)
{
	if (*(s.end() - 1) != 'f')
		return (0);

	double	num;
	char	*str_end;
	num = std::strtod(s.c_str(), &str_end);
	if (num && str_end[0] == 'f' && str_end[1] == '\0')
		return (1);
	return (0);
//	size_t pos = -1;
//	if ((pos = s.find('.', 0)) != std::string::npos)
//	{
//		size_t pos2 = 0;
//		if ((pos2 = s.find('.', pos + 1)) != std::string::npos)
//		{
//			std::cout << "double dots" <<std::endl;
//			return (0);
//		}
//	}
//	size_t	start = 0;
//	if (*(s.begin()) == '+' || *(s.begin()) == '-')
//		start = 1;
//	for (size_t i = start; i < s.length() - 1; ++i)
//	{
//		if (i != pos && !isdigit(s[i]))
//			return (0);
//	}
//	return (1);
}

int	ScalarConverter::checkDouble(std::string const &s)
{
	double	num;
	char	*str_end;

	num = std::strtod(s.c_str(), &str_end);
	if (num && str_end[0] == '\0')
		return (1);
	return (0);
//	std::string	const &dot = ".";
//	size_t	pos = 0;
//	size_t	pos2 = 0;
//	if((pos = s.find(dot, pos)) == std::string::npos)
//		return (0);
//	if ((pos2 = s.find(dot, pos + 1)) != std::string::npos)
//		return (0);
//	else
//	{
//		size_t	start = 0;
//		if (*(s.begin()) == '+' || *(s.begin()) == '-')
//			start = 1;
//		std::string::const_iterator dotpos = s.begin() + pos;
//		for (std::string::const_iterator it = s.begin() + start; it != s.end(); ++it)
//		{
//			if (it != dotpos && !isdigit(*it))
//				return (0);
//		}
//		return (1);
//	}
}

int		ScalarConverter::checkInt(std::string const &s)
{
	size_t	start = 0;
	if (*(s.begin()) == '+' || *(s.begin()) == '-')
		start = 1;
	for (std::string::const_iterator it = s.begin() + start; it != s.end(); ++it)
	{
		if (!isdigit(*it))
			return (0);
	}
	return (1);
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

void	ScalarConverter::convertChar(std::string const &s, s_result &res)
{
	char c = static_cast<char>(s[0]);
	res.c_res.displayable = true;
	res.c_res.possible = true;
	res.c_res.value = c;
	res.i_res.possible = true;
	res.i_res.value = static_cast<int>(c);
	res.f_res.possible = true;
	res.f_res.value = static_cast<float>(c);
	res.d_res.possible = true;
	res.d_res.value = static_cast<double>(c);
}

void	ScalarConverter::convertInt(std::string const &s, s_result &res)
{
	char	*str_end;
	double	num = strtod(s.c_str(), &str_end);
	if (num >= 32 && num < 127)
	{
		res.c_res.possible = true;
		res.c_res.displayable = true;
		res.c_res.value = static_cast<char>(num);
	}
	else if((num >= 0 && num < 32) || (num >= 127 && num < 128))
	{
		res.c_res.possible = true;
		res.c_res.displayable = false;
		res.c_res.value = static_cast<char>(num);
	}
	else
	{
		res.c_res.possible = false;
		res.c_res.displayable = false;
		res.c_res.value = static_cast<char>(num);
	}
	if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
	{
		res.i_res.possible = true;
		res.i_res.value = num;
	}
	else
	{
		res.i_res.possible = false;
		res.i_res.value = 0;
	}
	if (num >= (-1) * std::numeric_limits<float>::max() && num <= std::numeric_limits<float>::max())
	{
		res.f_res.possible = true;
		res.f_res.value = static_cast<float>(num);
	}
	if (num >= (-1) * std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::max())
	{
		res.d_res.possible = true;
		res.d_res.value = static_cast<double>(num);
	}
}

void	ScalarConverter::convertFloat(std::string const &s, s_result &res)
{
	char	*str_end;
	double	num = strtod(s.c_str(), &str_end);
	if (num >= 32 && num < 127)
	{
		res.c_res.possible = true;
		res.c_res.displayable = true;
		res.c_res.value = static_cast<char>(num);
	}
	else if((num >= 0 && num < 32) || (num >= 127 && num < 128))
		res.c_res.possible = true;
	if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
	{
		res.i_res.possible = true;
		res.i_res.value = num;
	}
	if (num >= (-1) * std::numeric_limits<float>::max() && num <= std::numeric_limits<float>::max())
	{
		res.f_res.possible = true;
		res.f_res.value = static_cast<float>(num);
	}
	if (num >= (-1) * std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::max())
	{
		res.d_res.possible = true;
		res.d_res.value = static_cast<double>(num);
	}
}

void	ScalarConverter::convertDouble(std::string const &s, s_result &res)
{
	char	*str_end;
	double	num = strtod(s.c_str(), &str_end);
	if (num >= 32 && num < 127)
	{
		res.c_res.possible = true;
		res.c_res.displayable = true;
		res.c_res.value = static_cast<char>(num);
	}
	else if((num >= 0 && num < 32) || (num >= 127 && num < 128))
		res.c_res.possible = true;
	if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
	{
		res.i_res.possible = true;
		res.i_res.value = num;
	}
	if (num >= (-1) * std::numeric_limits<float>::max() && num <= std::numeric_limits<float>::max())
	{
		res.f_res.possible = true;
		res.f_res.value = static_cast<float>(num);
	}
	if (num >= (-1) * std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::max())
	{
		res.d_res.possible = true;
		res.d_res.value = static_cast<double>(num);
	}
}

void	ScalarConverter::convert(std::string const &input)
{
	e_ScalarType	type = checkType(input);

	s_result	res;
	switch(type)
	{
		case TYPE_FLOAT_SYMBOL:
			convertFloatSymbol(input);
			break ;
		case TYPE_DOUBLE_SYMBOL:
			convertDoubleSymbol(input);
			break ;
		case TYPE_CHAR:
			convertChar(input, res);
			break ;
		case TYPE_INT:
			convertInt(input, res);
			break ;
		case TYPE_FLOAT:
			convertFloat(input, res);
			break ;
		case TYPE_DOUBLE:
			convertDouble(input, res);
			break ;
		case TYPE_INVALID:
			break ;
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	if (!res.c_res.possible)
		std::cout << "impossible";
	else if (!res.c_res.displayable)
		std::cout << "non displayable";
	else
		std::cout << "'" << res.c_res.value << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (!res.i_res.possible)
		std::cout << "impossible";
	else
		std::cout << res.i_res.value;
	std::cout << std::endl;

	std::cout << "float: ";
	if (!res.f_res.possible)
		std::cout << "impossible";
	else
		std::cout << res.f_res.value << "f";
	std::cout << std::endl;

	std::cout << "double: ";
	if (!res.d_res.possible)
		std::cout << "impossible";
	else
		std::cout << res.d_res.value;
	std::cout << std::endl;
}