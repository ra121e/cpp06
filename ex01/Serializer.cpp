/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:11:07 by athonda           #+#    #+#             */
/*   Updated: 2025/06/13 21:32:09 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	num;
	num = reinterpret_cast<uintptr_t>(ptr);
	return (num);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*data;
	data = reinterpret_cast<Data*>(raw);
	return (data);
}