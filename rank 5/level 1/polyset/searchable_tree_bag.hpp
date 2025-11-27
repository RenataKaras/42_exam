/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   searchable_tree_bag.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 16:33:36 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/27 15:07:57 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag
{
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &other);
		searchable_tree_bag &operator=(const searchable_tree_bag &other);
		~searchable_tree_bag();

		bool has(int value) const override;
};