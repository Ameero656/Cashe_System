#pragma once

#include <map>
#include <iostream>


class LRU_Cashe {
public:
	LRU_Cashe(int casheSize);

	bool processData(int data);
	
	std::map<int, std::pair<bool, int>> getCashe();

	void textDisplayCashe();

private:
	int casheSize;
	std::map<int, std::pair<bool, int>> cashe;

	bool calculateValue(int data);

	void addToCashe(int data, int value);
};