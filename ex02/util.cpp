/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:12:04 by athonda           #+#    #+#             */
/*   Updated: 2025/06/19 12:52:00 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "util.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base	*p;
	int		i;

	srand(clock());
	i = rand();
	if (i % 3 == 0)
		p = new A;
	else if(i % 3 == 1)
		p = new B;
	else
		p = new C;

	return (p);
}

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "This is A!" << std::endl;
	else if(b != NULL)
		std::cout << "This is B!" << std::endl;
	else if (c != NULL)
		std::cout << "This is C!" << std::endl;
	else
		std::cout << "This is error!" << std::endl;

}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "This is A!" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "This is B!" << std::endl;
		}
		catch(std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "This is C!" << std::endl;
			}
			catch(std::exception &e)
			{
				e.what();
				std::cout << "This is error!" << std::endl;
			}
		}
	}
}