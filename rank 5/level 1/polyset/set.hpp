/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/27 14:57:57 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/27 16:02:38 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_bag.hpp"

#ifndef SET_H
#define SET_H

class set
{
	private:
		searchable_bag &_bag;
	public:
		set(searchable_bag &bag);
		set(const set& other);
		set& operator=(const set& other);
		~set();
		
		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();

		bool has(int) const;

		searchable_bag &get_bag() const;

};

#endif /* !SET_H */