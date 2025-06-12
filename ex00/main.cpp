/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:49:47 by athonda           #+#    #+#             */
/*   Updated: 2025/06/12 19:21:10 by athonda          ###   ########.fr       */
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
	(void)ac;
	std::string	input = av[1];
	ScalarConverter::convert(av[1]);
//	(void)av;
//	float	a = 4e87;
//	std::cout << "a: " << a << std::endl;
//	float	z = std::numeric_limits<float>::infinity();
//	std::cout << "z: " << z << std::endl;
//
//	if (z == a)
//		std::cout << "compare a(4e87) to infinity " << std::endl;
//	else
//		std::cout << "error" << std::endl;
//
//	int	i = std::numeric_limits<int>::infinity();
//	std::cout << "int i: " << i << std::endl;
//
//	int	c = std::numeric_limits<char>::infinity();
//	std::cout << "int c: " << c << std::endl;
//
//	double	max = std::numeric_limits<double>::max();
//	std::cout << std::setprecision(20);
//	std::cout << "max is " << max << std::endl;
//	std::cout << "max + 1 = " << max + 1 << std::endl;
//
//	double prev = ::nextafter(max, 0.0);
//	std::cout << "prev is " << prev << std::endl;
//
//	double eps = max - prev;
//	std::cout << "epsilon is " << eps << std::endl;
//
//	double inf = max + eps;
//	std::cout << "inf? " << inf << std::endl;
//
//	double	maxf = std::numeric_limits<float>::max();
//	std::cout << "max is " << maxf << std::endl;
//
//	double prevf = ::nextafter(maxf, 0.0);
//	std::cout << "prev is " << prevf << std::endl;
//
//	double epsf = maxf - prevf;
//	std::cout << "epsilon is " << epsf << std::endl;
//
//	float inff = maxf + epsf + 0.00000011e+38;
//	std::cout << "inf? " << inff << std::endl;
	return (0);
}