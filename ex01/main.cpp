/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:04:19 by athonda           #+#    #+#             */
/*   Updated: 2025/06/19 13:35:35 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Data.hpp"
#include "Serializer.hpp"

void	printBanner(std::string title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	Data	a;
	printBanner("Simple test for address of struct.");
	std::cout << "Here are the members of struct a" << std::endl;
	std::cout << "char c: " << a.c << std::endl;
	std::cout << "string: " << a.str << std::endl;
	std::cout << "int num: " << a.num << std::endl;
	std::cout << "address of struct a: " << &a << std::endl;

	uintptr_t	b;
	std::cout << "serialize address type to number type" << std::endl;
	b = Serializer::serialize(&a);
	std::cout << "Serialized value of the ex-address value of struct a: " << b << std::endl;
	std::cout << "its same bit patern, but the translated meaning is different." << std::endl;

	Data	*c;
	std::cout << "Now, desirialize the number b to address" << std::endl;
	c = Serializer::deserialize(b);
	std::cout << "the inside of the dederialized address " << std::endl;
	std::cout << "address of b: " << c << std::endl;
	std::cout << "char c: " << c->c << std::endl;

	// extra test for cast
	Data_s	*ss;
	printBanner("extra test for casting the large struct to small struct.");
	std::cout << "Now, this is extra test for reinterpret_cast" << std::endl;
	std::cout << "cast from Data class which has 3 members to Data_s class which has 2 members" << std::endl;
	ss = reinterpret_cast<Data_s*>(c);

	std::cout << "the small struct address: " << ss << std::endl;
	std::cout << "char in the small struct " << ss->c << std::endl;
	std::cout << "string in the small struct " << ss->str << std::endl;
	std::cout << "we can call only 2 members because compiler restrict" << std::endl;
	std::cout << "Trying to access to the third member makes compile error" << std::endl;

	// compile error
	// std::cout << ss.num << std::endl;

	Data_s	t;
	Data	*u;

	u = reinterpret_cast<Data*>(&t);
	printBanner("extra test for casting from smalll struct to large struct");
	std::cout << "if small class casted to large class, we can access to the outside of class" << std::endl;
	std::cout << "first line: " << u->c << std::endl;
	std::cout << "second line: " << u->str << std::endl;
	std::cout << "third line: " << u->num << std::endl;
	std::cout << "This is the risk of reinterpret_cast" << std::endl;

	// char* and int* case
	printBanner("char* and int*");
	{
	char	s[5] = {'a', 'b', 'c', 'd', '\0'};
	char	*str;
	str = s;
	int		*num;
	std::cout << "str: " << str << std::endl;
	std::cout << "str[0]: " << str[0] << std::endl;
	std::cout << "Now, cast char string to int pointer" << std::endl;
	num = reinterpret_cast<int*>(str);
	std::cout << "int dereference: " << *num << std::endl;
	std::cout << "now, change the value in the address" << std::endl;
	*num = 1684234850;
	std::cout << "int is: " << *num << std::endl;
	std::cout << "Then, cast back int pointer to char pointer" << std::endl;
	str = reinterpret_cast<char*>(num);
	std::cout << str << std::endl;
	}

	// multiple pointer cases
	printBanner("char** and int**");
	{
	char	s[5] = {'a', 'b', 'c', 'd', '\0'};
	char	*str1;
	char	**str;
	str1 = s;
	str = &str1;
	int		*num1;
	int		**num;
	num = &num1;
	std::cout << "str: " << *str << std::endl;
	std::cout << "str[0]: " << *str[0] << std::endl;
	std::cout << "Now, cast char string to int pointer" << std::endl;
	num = reinterpret_cast<int**>(str);
	std::cout << "int dereference: " << **num << std::endl;
	std::cout << "now, change the value in the address" << std::endl;
	**num = 1684234850;
	std::cout << "int is: " << **num << std::endl;
	std::cout << "Then, cast back int pointer to char pointer" << std::endl;
	str = reinterpret_cast<char**>(num);
	std::cout << *str << std::endl;
	}

	return (0);
}