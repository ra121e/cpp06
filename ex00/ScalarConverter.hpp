/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:33:08 by athonda           #+#    #+#             */
/*   Updated: 2025/06/07 08:28:18 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string const &input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter	&operator=(ScalarConverter const &other);

		int	checkType(std::string const &s);
};