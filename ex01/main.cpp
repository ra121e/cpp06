/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:04:19 by athonda           #+#    #+#             */
/*   Updated: 2025/06/17 21:33:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data	a;
	std::cout << "this is the members of a" << std::endl;
	std::cout << "char c: " << a.c << std::endl;
	std::cout << "string: " << a.str << std::endl;
	std::cout << "int num: " << a.num << std::endl;
	std::cout << "address of a: " << &a << std::endl;

	uintptr_t	b;
	std::cout << "serialize address of a to number" << std::endl;
	b = Serializer::serialize(&a);
	std::cout << "Serialized address a: " << b << std::endl;

	Data	*c;
	std::cout << "Now, desirialize the number b to address" << std::endl;
	c = Serializer::deserialize(b);
	std::cout << "the inside of the dederialized address " << std::endl;
	std::cout << "address of b: " << c << std::endl;
	std::cout << "char c: " << c->c << std::endl;

	// extra test for cast
	Data	s;
	Data_s	*ss;
	std::cout << "Now, this is extra test for reinterpret_cast" << std::endl;
	std::cout << "cast from Data class which has 3 members to Data_s class which has 2 members" << std::endl;
	ss = reinterpret_cast<Data_s*>(&s);

	std::cout << "short struct address: " << ss << std::endl;
	std::cout << "char of ss " << ss->c << std::endl;
	std::cout << "string of ss " << ss->str << std::endl;
	std::cout << "we can call only 2 members for compiler restrict" << std::endl;

	Data_s	t;
	Data	*u;

	u = reinterpret_cast<Data*>(&t);
	std::cout << "if small class casted to large class, we can access to the outside of class" << std::endl;
	std::cout << "first line: " << u->c << std::endl;
	std::cout << "second line: " << u->str << std::endl;
	std::cout << "third line: " << u->num << std::endl;
	return (0);
}