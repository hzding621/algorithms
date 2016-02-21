/**
 * @file dsets.cpp
 * Definition of the disjoint sets class.
 */

#include "dsets.h"

void dsets::add_elements(uint64_t num)
{
	for (uint64_t i = 0; i < num ; ++i)
		arr_.push_back(-1);
}

uint64_t dsets::find(uint64_t elem)
{
	if (arr_[elem] < 0)
		return elem;
	else
		return arr_[elem] = find(arr_[elem]);
}

void dsets::merge(uint64_t a, uint64_t b)
{
	auto a_root = find(a);
	auto b_root = find(b);

	if (a_root == b_root)
		return;

	if (arr_[a_root] > arr_[b_root])
	{	
		arr_[b_root] += arr_[a_root];
		arr_[a_root] = b_root;
	}
	else 
	{
		arr_[a_root] += arr_[b_root];
		arr_[b_root] = a_root;
	}
	return;
}