/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:12:04 by athonda           #+#    #+#             */
/*   Updated: 2025/06/18 22:55:20 by athonda          ###   ########.fr       */
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
		dynamic_cast<A&>(p);
		std::cout << "This is A!" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "This is B!" << std::endl;
		}
		catch(std::bad_cast const &e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "This is C!" << std::endl;
			}
			catch(std::bad_cast const &e)
			{
				e.what();
				std::cout << "This is error!" << std::endl;
			}
		}
	}
}