/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   searchable_array_bag.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 16:30:34 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 17:02:54 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &other);
		searchable_array_bag &operator=(const searchable_array_bag &other);
		~searchable_array_bag();

		bool has(int value) const override;
};