#pragma once
#include <unordered_set>
#include <vector>

class SetCompare
{
private:

public:
	float accuracy = 0;
	void compare(std::vector<int> a, std::unordered_set<int>* b);
};