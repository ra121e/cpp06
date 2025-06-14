/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:12:04 by athonda           #+#    #+#             */
/*   Updated: 2025/06/14 16:28:16 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base	*p = new B;
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
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(&p);
	b = dynamic_cast<B*>(&p);
	c = dynamic_cast<C*>(&p);

	if (a != NULL)
		std::cout << "This is A!" << std::endl;
	else if(b != NULL)
		std::cout << "This is B!" << std::endl;
	else if (c != NULL)
		std::cout << "This is C!" << std::endl;
	else
		std::cout << "This is error!" << std::endl;


}