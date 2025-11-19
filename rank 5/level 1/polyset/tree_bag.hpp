/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_bag.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 15:11:37 by rkaras        #+#    #+#                 */
/*   Updated: 2025/11/19 15:14:51 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class tree_bag : virtual public bag {
protected:
	// binary search tree node structure
	struct node {
	  node *l;
	  node *r;
	  int value;
	};

	node *tree; // root node

public:
	tree_bag();
	tree_bag(const tree_bag &);
	tree_bag  &operator=(const tree_bag &);
	~tree_bag();

	node *extract_tree(); // getter
	void set_tree(node *); // sets the tree as an incoming argument it receives

	virtual void insert(int);
	virtual void insert(int *array, int size);
	virtual void print() const;
	virtual void clear();

private:
	static void destroy_tree(node *);
	static void print_node(node *);
	static node *copy_node(node *);
};