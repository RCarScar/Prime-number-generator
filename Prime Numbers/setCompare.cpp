#include "setCompare.h"
#include <iostream>

void SetCompare::compare(std::vector<int> result, std::unordered_set<int>* set)
{
	int counter = 0;
	for (int i : result)
	{
		if (set->find(i) != set->end())
			counter++;
	}

	if (result.size() == 0)
	{
		std::cout << "the set is empty." << std::endl;
		return;
	}
	accuracy = ((float)counter / result.size());
	return;
}