/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:33:08 by athonda           #+#    #+#             */
/*   Updated: 2025/06/13 10:46:07 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

enum e_ScalarType
{
	TYPE_FLOAT_SYMBOL,
	TYPE_DOUBLE_SYMBOL,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

class ScalarConverter
{
	public:
		static void	convert(std::string const &input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter	&operator=(ScalarConverter const &other);

		static e_ScalarType	checkType(std::string const &s);
		static int	checkFloatSymbol(std::string const &s);
		static int	checkDoubleSymbol(std::string const &s);
		static int	checkChar(std::string const &s);
		static int	checkInt(std::string const &s);
		static int	checkDouble(std::string const &s);
		static int	checkFloat(std::string const &s);

		static void	convertFloatSymbol(std::string const &s);
		static void	convertDoubleSymbol(std::string const &s);
		static void	convertChar(std::string const &s);
		static void	convertFloat(std::string const &s);
		static void	convertDouble(std::string const &s);
		static void	convertInt(std::string const &s);
		static void	convertInvalid(std::string const &s);
};
