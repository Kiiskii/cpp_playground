#pragma once

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

#include <map>
#include <string>
class BitcoinExchange {
private:
	std::map<std::string, float> _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other) = delete;
	BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
	~BitcoinExchange() = default;

	void databaseToMap();

	void processInput(std::string& filename);
	void parseLine(std::string& line);
	bool validateDate(std::string& date);
	float findRate(std::string& date);
	bool validateValue(std::string& valueStr);
};
