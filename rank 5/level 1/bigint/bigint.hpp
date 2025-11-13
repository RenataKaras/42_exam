/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigint.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/13 15:35:23 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/13 17:20:30 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
#define BIGINT_H

#include "iostream"
#include "sstream"

class bigint
{
	private:
		std::string _str;

	public:
		bigint();
		bigint(unsigned int number);
		bigint(const bigint& other);
		bigint &operator=(const bigint& other);
		~bigint();

		std::string getStr() const;

		//addition + +=

		//increments ++x x++

		//digshift << <<= >> >>=
		
		//comparison == != > < <= >=
		bool operator<(const bigint &other);
		bool operator>(const bigint &other);
		bool operator>=(const bigint &other);
		bool operator<=(const bigint &other);
		bool operator==(const bigint &other);
		bool operator!=(const bigint &other);
};

std::ostream &operator<<(std::ostream &output, const bigint &object);

#endif /* !BIGINT_H */