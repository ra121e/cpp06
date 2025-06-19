/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:49:47 by athonda           #+#    #+#             */
/*   Updated: 2025/06/19 21:44:18 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./Converter <somthing> " << std::endl;
		return (0);
	}
	std::string	input = av[1];
	ScalarConverter::convert(input);
	return (0);
}