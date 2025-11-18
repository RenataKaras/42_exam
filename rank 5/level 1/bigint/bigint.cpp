/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigint.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/13 15:36:40 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/18 15:14:37 by rkaras        ########   odam.nl         */
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

unsigned int bigint::toUint() const
{
	unsigned int result = 0;

	for (size_t i = 0; i < _str.size(); i++)
		result = result * 10 + (_str[i] - '0');
	return (result);
}

//output overload
std::ostream &operator<<(std::ostream &output, const bigint &object) {
	output << object.getStr();
	return (output);
}

//comparisons
bool bigint::operator<(const bigint &other)  const {
	std::string str1 = _str;
	std::string str2 = other.getStr();

	if (str1.size() != str2.size())
		return (str1.size() < str2.size());

	return (str1 < str2);
}

bool bigint::operator>(const bigint &other) {
	return (other < *this);
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

//additions

bigint &bigint::operator+=(const bigint &other)
{
	std::string result ("");
	int carry = 0;
	
	int i = _str.size() - 1;
	int j = other._str.size() - 1;

	while (i >= 0 || j >= 0 || carry != 0)
	{
		int digit1 = 0;
		int digit2 = 0;

		if (i >= 0)
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

	return *this;
}

bigint bigint::operator+(const bigint &other) const
{
	bigint temp = *this;
	temp += other;
	return temp;
}

bigint &bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	++(*this);
	return (temp);
}

//digitshift

bigint &bigint::operator<<=(const bigint &other)
{
	unsigned int n = other.toUint();
	
	if (n == 0)
		return (*this);

	while (n > 0)
	{
		_str.push_back('0');
		n--;
	}
	return *this;
}

bigint &bigint::operator>>=(const bigint &other)
{
	unsigned int n = other.toUint();
	if (n == 0)
		return *this;

	if (n >= _str.size())
	{
		_str = "0";
		return *this;
	}
	
	while(n > 0)
	{
		_str.pop_back();
		n--;
	}
	
	return (*this);
}

bigint bigint::operator>>(const bigint &other)
{
	bigint temp = *this;
	temp >>= other;
	return temp;
}

bigint bigint::operator<<(const bigint &other)
{
	bigint temp = *this;
	temp <<= other;
	return temp;
}
