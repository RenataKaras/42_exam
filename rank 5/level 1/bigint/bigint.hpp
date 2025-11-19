/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigint.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 13:16:54 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 14:48:45 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

#include <iostream>
#include <algorithm>
#include <sstream>

class bigint
{
	private:
		std::string _str;

	public:
		bigint() = default;
		bigint(unsigned int num);
		bigint(const bigint &other) = default;
		bigint &operator=(const bigint &other) = default;
		~bigint() = default;

		std::string getStr() const;
		unsigned int toUint() const;
		
		//addition
		bigint &operator+=(const bigint &other);
		bigint operator+(const bigint &other) const;
		bigint &operator++(); //++b
		bigint operator++(int); //b++

		//digitshift
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(const bigint &other);
		bigint operator>>(const bigint &other) const;
		bigint operator<<(const bigint &other) const;

		//comparisons
		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
};

std::ostream &operator<<(std::ostream &output, const bigint &object);

#endif