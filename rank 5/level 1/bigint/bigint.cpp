/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigint.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/13 15:36:40 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/13 17:21:15 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint() : _str("0") {}

bigint::bigint(unsigned int number) {
	std::stringstream ss;
	ss << number;
	_str = ss.str();
}

bigint::bigint(const bigint &other) : _str(other._str) {};

bigint &bigint::operator=(const bigint &other) {
	if (this != &other)
		_str = other._str;
	return (*this);
}

bigint::~bigint() {};

std::string bigint::getStr() const {
	return (_str);
}

//output overload
std::ostream &operator<<(std::ostream &output, const bigint &object) {
	output << object.getStr();
	return (output);
}

//comparisons
bool bigint::operator<(const bigint &other) {
	std::string str1 = _str;
	std::string str2 = other.getStr();

	if (str1.size() != str2.size())
		return (str1.size() < str2.size());

	return (str1 < str2);
}

bool bigint::operator>(const bigint &other) {
	return (*this < other);
}

bool bigint::operator>=(const bigint &other) {
	return !(*this < other);
}

bool bigint::operator<=(const bigint &other) {
	return !(*this > other);
}

bool bigint::operator==(const bigint &other) {
	return (_str == other.getStr());
}

bool bigint::operator!=(const bigint &other) {
	return !(*this == other);
}

