/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   seachable_array_bag.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/27 15:10:36 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/27 15:34:30 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other)
	: array_bag(other) { }

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other)
		array_bag::operator=(other);
	return (*this);
}

searchable_array_bag::~searchable_array_bag() { }

bool searchable_array_bag::has(int value) const {
	for (int i = 0; i < size; i++) {
		if (this->data[i] == value)
			return true;
	}
	return false;
}