#include <string>
#include <iostream>
#include "txtToBinary.h"
#include <fstream>

int ConvertBintoSet::begin(std::string inputFilePath, std::string outputFilePath)
{
	// open the txt
	std::ifstream inputFile(inputFilePath);

	// open the file now
	std::ofstream outFile(outputFilePath, std::ios::binary);

	// Check if the file was opened successfully
	if (!outFile.is_open()) {
		std::cerr << "Failed to open output : " << outputFilePath << std::endl;
		return 1;
	}

	int currentNum;
	int count = 0;

	// Streaming Loop
	std::cout << "Conversion Beginning: " << std::endl;
	while (inputFile >> currentNum)
	{
		outFile.write(reinterpret_cast<const char*>(&currentNum), sizeof(currentNum));
		count++;
	}

	// 5. close the file.
	inputFile.close();
	outFile.close();

	std::cout << "Completed." << std::endl;
	return 0;
}


std::unordered_set<int>* ConvertBintoSet::readBinaryFile(std::string path)
{
	result = new std::unordered_set<int>();

	// open the file
	std::ifstream inputFile(path, std::ios::binary);

	// if not open big issue
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open file." << std::endl;
		return result;
	}

	// louisianna purchase
	result->reserve(1000000);

	int currentNumber;
	int totalRead = 0;

	// Read the file 4 bytes at a time.
	while (inputFile.read(reinterpret_cast<char*>(&currentNumber), sizeof(currentNumber)))
	{
		result->insert(currentNumber);
		totalRead++;
	}

	return result;
}


void ConvertBintoSet::printResults(std::unordered_set<int>* override = NULL)
{
	// If override print that and end.
	if (override != NULL)
	{
		std::cout << "\nOverride triggered set contents:\n";
		for (int number : *override) {
			std::cout << number << " ";
		}
		std::cout << "\n";
		return;
	}

	// Print class info
	if (result == NULL)
	{
		std::cerr << "Printing Failed, set is NULL." << std::endl;
		return;
	}
	std::cout << "\nVerifying set contents:\n";
	for (int number : *result) {
		std::cout << number << " ";
	}
	std::cout << "\n";
	return;
}
std::unordered_set<int>* ConvertBintoSet::getResults()
{
	return result;
}

ConvertBintoSet::~ConvertBintoSet()
{
	delete result;
}