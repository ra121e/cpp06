/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:17:33 by athonda           #+#    #+#             */
/*   Updated: 2025/06/17 21:18:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

typedef struct s_data Data;
typedef struct s_data_short Data_s;

struct s_data
{
	char		c;
	std::string	str;
	int			num;

	s_data():
		c('A'),
		str("42Singapore"),
		num(42)
	{}
};

struct s_data_short
{
	char	c;
	std::string	str;

	s_data_short():
		c('s'),
		str("short")
	{}
};