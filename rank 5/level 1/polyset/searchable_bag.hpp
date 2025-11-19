/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   searchable_bag.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 15:05:22 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 16:44:05 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class searchable_bag : virtual public bag // virtual inheritance
{
 public:
	virtual bool has(int) const = 0; //checks if the given number is in the bag or not
};