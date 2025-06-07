/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:34 by athonda           #+#    #+#             */
/*   Updated: 2025/06/07 14:47:50 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>		// isdigit
#include <string>		// string
#include <iostream>		// std::cout
#include "ScalarConverter.hpp"

int		ScalarConverter::checkChar(std::string const &s)
{
	if (s.length() == 1 && !isdigit(s[0]))
		return (1);
	return (0);
}

e_ScalarType		ScalarConverter::checkType(std::string const &s)
{
	if (checkChar(s))
		return (TYPE_CHAR);
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