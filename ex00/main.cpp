/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:49:47 by athonda           #+#    #+#             */
/*   Updated: 2025/06/12 12:57:22 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

int	main(int ac, char **av)
{
	(void)ac;
//	std::string	input = av[1]
//	ScalarConverter::convert(av[1]);
	(void)av;
	float	a = 4e87;
	std::cout << a << std::endl;

	double	b = std::numeric_limits<double>::max();
	std::cout << b << std::endl;
	return (0);
}