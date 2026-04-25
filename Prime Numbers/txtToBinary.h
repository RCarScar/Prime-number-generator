#pragma once
#include <string>
#include <unordered_set>

class ConvertBintoSet
{
public:
	int begin(std::string inputFilePath, std::string outputFilePath);
	std::unordered_set<int> *readBinaryFile(std::string path);
	void printResults(std::unordered_set<int>* override);
	std::unordered_set<int>* getResults();
	~ConvertBintoSet();
private:
	std::unordered_set<int>* result = new std::unordered_set<int>();
};