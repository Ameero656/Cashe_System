#include "LRU_Cashe.h"

#include <vector>
#include <random>
#include <cmath>

std::vector<int> generateRawData(int digits, int size) {
	std::vector<int> data;

	for (int i = 0; i < size; i++) {
		data.push_back(rand() % static_cast<int>(pow(10, digits)));
	}
	
	return data;
}

int main() {
	srand(time(NULL));


	LRU_Cashe casheSystem(25); //create a cash with n memory slots

	std::vector<int> rawData = generateRawData(6, 150);
	std::vector<int> selData = { -1, -2, -3, -4, -5 };

	int iterations = 200;
	for (int i = 0; i < iterations; i++) {
		if (i % 2 == 0) casheSystem.processData(rawData[rand() % rawData.size()]);
		else casheSystem.processData(selData[rand() % selData.size()]);
	}
	casheSystem.textDisplayCashe();
	
	
}