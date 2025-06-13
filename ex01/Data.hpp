/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:17:33 by athonda           #+#    #+#             */
/*   Updated: 2025/06/13 20:57:51 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

typedef struct s_data Data;
struct s_data
{
	char		c;
	std::string	str;
	int			num;

	s_data():
		c('a'),
		str("42Singapore"),
		num(42)
	{}
};