#include "LRU_Cashe.h"


LRU_Cashe::LRU_Cashe(int casheSize) : casheSize(casheSize) {};

bool LRU_Cashe::calculateValue(int data) {
	return data % 2 == 0 ? true : false;
}

void LRU_Cashe::addToCashe(int data, int value) {
	if (LRU_Cashe::cashe.size() == LRU_Cashe::casheSize) {
		auto leastRecentDataIt = LRU_Cashe::cashe.begin();
		int leastRecentDataValue = 2147483647;
		for (auto it = LRU_Cashe::cashe.begin(); it != LRU_Cashe::cashe.end(); it++) {
			if (it->second.second < leastRecentDataValue) {
				leastRecentDataValue = it->second.second;
				leastRecentDataIt = it;
			}
		}
		LRU_Cashe::cashe.erase(leastRecentDataIt);
	}
	LRU_Cashe::cashe.insert({ data, {value, 1} });
}

bool LRU_Cashe::processData(int data) {
	int proccessies = 0;
	
	auto it = LRU_Cashe::cashe.find(data);
	
	if (it != LRU_Cashe::cashe.end()) {
		it->second.second++;
		return LRU_Cashe::cashe[data].first;
	}
	proccessies++;
	bool value = LRU_Cashe::calculateValue(data);

	LRU_Cashe::addToCashe(data, value);
	return value;

}

std::map<int, std::pair<bool, int>> LRU_Cashe::getCashe() {
	return LRU_Cashe::cashe;
}

void LRU_Cashe::textDisplayCashe() {
	for (const auto& keyValuePair: LRU_Cashe::cashe) {
		std::cout << keyValuePair.first << "->" << keyValuePair.second.first << std::endl;
		std::cout << "--L " << keyValuePair.second.second << " recent requests\n\n";
	}
}