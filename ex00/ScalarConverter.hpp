/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:33:08 by athonda           #+#    #+#             */
/*   Updated: 2025/06/19 18:57:27 by athonda          ###   ########.fr       */
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

struct s_result_c
{
	char	value;
	bool	possible;
	bool	displayable;

	s_result_c():
		value(0),
		possible(false),
		displayable(false)
	{}
};

struct s_result_i
{
	int		value;
	bool	possible;

	s_result_i():
		value(0),
		possible(false)
	{}
};

struct s_result_f
{
	float	value;
	bool	possible;

	s_result_f():
		value(0.0f),
		possible(false)
	{}
};

struct s_result_d
{
	double	value;
	bool	possible;

	s_result_d():
		value(0.0),
		possible(false)
	{}
};

struct	s_result
{
	struct s_result_c	c_res;
	struct s_result_i	i_res;
	struct s_result_f	f_res;
	struct s_result_d	d_res;

	s_result()
	{}
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
		static void	convertDoubleSymbol(std::string const &s, s_result &res);
		static void	convertChar(std::string const &s, s_result &res);
		static void	convertInt(std::string const &s, s_result &res);
		static void	convertFloat(std::string const &s, s_result &res);
		static void	convertDouble(std::string const &s, s_result &res);
		static void	convertInvalid(std::string const &s);
};
