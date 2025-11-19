/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bag.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 15:00:57 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 15:04:38 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once //prevents multiple include - after this file has been included once, ignore if it happens again


// bag data structute is equivalent to a multiset?
// it is a structure that holds a data item and the number of instances of it
class bag
{
 public:
	virtual void insert (int) = 0;
	virtual void insert (int *, int) = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};