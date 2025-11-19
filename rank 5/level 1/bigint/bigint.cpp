/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigint.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 13:16:57 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 14:49:54 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint(unsigned int num) {
	std::stringstream ss;
	ss << num;
	_str = ss.str();
}

std::string bigint::getStr() const {
	return _str;
}

std::ostream &operator<<(std::ostream &output, const bigint &object) {
	output << object.getStr();
	return (output);
}

bigint &bigint::operator+=(const bigint &other) {
	int i = _str.size() - 1;
	int j = other._str.size() - 1;

	int carry = 0;
	std::string result;

	while (i >= 0 || j >= 0 || carry != 0)
	{
		int digit1 = 0;
		int digit2 = 0;
		
		if(i >= 0)
			digit1 = _str[i] - '0';
		if (j >= 0)
			digit2 = other._str[j] - '0';

		int sum = digit1 + digit2 + carry;
		carry = sum / 10;

		result.push_back((sum % 10) + '0');
		i--;
		j--;
	}
	std::reverse(result.begin(), result.end());

	_str = result;
	return (*this);
}

bigint bigint::operator+(const bigint &other) const{
	bigint temp = *this;
	temp += other;
	return (temp);
}

bigint &bigint::operator++() {
	*this += bigint(1);
	return (*this);
}

bigint bigint::operator++(int) {
	bigint temp = *this;
	++(*this);
	return (temp);
}

unsigned int bigint::toUint() const {
	unsigned int num = 0;

	for (size_t i = 0; i < _str.size(); i++)
		num = num * 10 + (_str[i] - '0');
	
	return (num);
}

bigint &bigint::operator<<=(const bigint &other) {
	unsigned int n = other.toUint();
	
	if (n == 0)
		return (*this);

	for (; n > 0; n--)
		_str.push_back('0');
	
	return (*this);
}

bigint &bigint::operator>>=(const bigint &other) {
	unsigned int n = other.toUint();

	if (n == 0)
		return (*this);

	if (n >= _str.size()) {
		_str = "0";
		return (*this);
	}

	for (; n > 0; n--)
		_str.pop_back();

	return (*this);
}

bigint bigint::operator<<(const bigint &other) const {
	bigint temp = *this;
	temp <<= other;
	return (temp);
}

bigint bigint::operator>>(const bigint &other) const {
	bigint temp = *this;
	temp >>= other;
	return (temp);
}

bool bigint::operator<(const bigint &other) const {
	std::string str1 = _str;
	std::string str2 = other._str;
	
	if (_str.size() != other._str.size())
		return (_str.size() < other._str.size());
	
	return (str1 < str2);
}
		
bool bigint::operator>(const bigint &other) const {
	return (other < *this);
}

bool bigint::operator<=(const bigint &other) const {
	return !(*this > other);
}

bool bigint::operator>=(const bigint &other) const {
	return !(*this < other);
}
		
bool bigint::operator==(const bigint &other) const {
	return (_str == other._str);
}

bool bigint::operator!=(const bigint &other) const {
	return !(*this == other);
}