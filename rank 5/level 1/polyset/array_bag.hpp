/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_bag.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 15:09:25 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 16:45:11 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class array_bag : virtual public bag
{
 protected:
	int *data;
	int size;

 public:
	array_bag();
	array_bag(const array_bag &);
	array_bag &operator=(const array_bag &other);
	~array_bag();

	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
};