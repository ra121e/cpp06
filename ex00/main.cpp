/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:49:47 by athonda           #+#    #+#             */
/*   Updated: 2025/06/07 13:18:34 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	(void)ac;
//	std::string	input = av[1]
	ScalarConverter::convert(av[1]);
	return (0);
}