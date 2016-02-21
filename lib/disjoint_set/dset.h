/**
 * @file dsets.h
 * Declaration of the disjoint sets class
 */

#ifndef DSETS_H
#define DSETS_H

#include <cstdint>
#include <vector>

/**
 * Each dsets object represents a family of disjoint sets, 
 * where each element has an integer index.
 *
 * It is implemented with the optimizations discussed in class, 
 * as up-trees stored in a single vector of ints. Specifically, 
 * path compression and union-by-size are used. Each place in the 
 * vector represents a node. (Note that this means that the elements 
 * in our universe are indexed starting at 0.) A nonnegative number 
 * is the index of the parent of the current node; a negative number 
 * in a root node is the negative of the set size.
 *
 * Note that the default compiler-supplied Big Five will work flawlessly 
 * because the only member data is a vector of integers and this vector 
 * should initially be empty.
 */

class dsets
{

  public:

	/**
	 * Creates n unconnected root nodes at the end of the vector.
	 * @param num The number of nodes to create
	 */ 
	void add_elements(uint64_t num);

	/**
	 * This function should compress paths and works as described in lecture.
	 * @return the index of the root of the up-tree in which the parameter element resides
	 */
	uint64_t find(uint64_t elem);

	/**
	 * This function should be implemented using union-by-size.
	 * Your merge function SHOULD find the roots of its arguments before combining the trees. 
	 * If the two sets are the same size, break the tie by making the root 
	 * of the second argument point at the root of the first. 
	 * (You should be able to break this tie arbitrarily—this just makes things easier to grade.)
	 * @param a Index of the first element to union
	 * @param b Index of the second element to union
	 */	
	void merge(uint64_t a, uint64_t b);

  private:

  	/*
	 * The storage for your sets.
	 */
  	std::vector<int64_t> arr_;

};

#endif