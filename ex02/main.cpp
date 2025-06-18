/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:55:58 by athonda           #+#    #+#             */
/*   Updated: 2025/06/18 15:33:46 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "util.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

using std::cout;
using std::endl;

void	printBanner(std::string title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	Base	*p;
	printBanner("first test for pointer");
	p = generate();
	identify(p);
	delete (p);

	printBanner("second test: reference");
	A	a;
	B	b;
	C	c;
	identify(a);
	identify(b);
	identify(c);

	return (0);
}