/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:34 by athonda           #+#    #+#             */
/*   Updated: 2025/06/08 13:16:19 by athonda          ###   ########.fr       */
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
	std::cout << s << std::endl;
	return (0);
}

int	ScalarConverter::checkDouble(std::string const &s)
{
	std::cout << s << std::endl;
	return (0);
}

int	ScalarConverter::checkFloat(std::string const &s)
{
	std::cout << s << std::endl;
	return (0);
}

e_ScalarType		ScalarConverter::checkType(std::string const &s)
{
	if (checkChar(s))
		return (TYPE_CHAR);
	else if (checkInt(s))
		return (TYPE_INT);
	else if (checkDouble(s))
		return (TYPE_DOUBLE);
	else if (checkFloat(s))
		return (TYPE_FLOAT);
	return (TYPE_INVALID);
}

void	ScalarConverter::convert(std::string const &input)
{
	std::cout << input << std::endl;
	e_ScalarType	type = checkType(input);

	//test for iterator
	std::istream_iterator<char>	a(std::cin);
	std::istream_iterator<char>	b;

	std::cout << "iterator a is " << *a << std::endl;
	++a;
	std::cout << "iterator a after increment is " << *a << std::endl;
	std::cout << "iterator b as end is " << *b << std::endl;

	// test for inside of std::cin
	//std::streambuf *buf = std::cin.rdbuf();
	//int c = buf->sbumpc();
	//std::cout << "the ascii number of input is: " << c << std::endl;


	//normal >>
	//std::string str;
	//std::cin >> str;
	//std::cout << "cin test: str " << str << std::endl;
	//std::cout << "cin test: std::cin " << std::cin << std::endl;

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