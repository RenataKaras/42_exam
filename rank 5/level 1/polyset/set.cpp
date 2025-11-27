/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/27 15:43:16 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/27 16:33:31 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag &bag) : _bag(bag) {}

set::set(const set &other) : _bag(other._bag) {}

set& set::operator=(const set &other) {
	if (this != &other)
	{
		
	}
	return (*this);
}

set::~set() {}

void set::insert(int value) {
	if (!_bag.has(value))
		_bag.insert(value);
}

void set::insert(int *arr, int size) {
	for (int i = 0; i < size; i++)
		insert(arr[i]);
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}

searchable_bag &set::get_bag() const {
	return _bag;
}

bool set::has(int value) const {
	return _bag.has(value);
}