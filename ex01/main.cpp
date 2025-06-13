/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:04:19 by athonda           #+#    #+#             */
/*   Updated: 2025/06/13 21:45:30 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data	a;
	std::cout << "char c: " << a.c << std::endl;
	std::cout << "string: " << a.str << std::endl;
	std::cout << "int num: " << a.num << std::endl;
	std::cout << "address of a: " << &a << std::endl;

	uintptr_t	b;
	b = Serializer::serialize(&a);
	std::cout << "address of a: " << b << std::endl;
	return (0);
}