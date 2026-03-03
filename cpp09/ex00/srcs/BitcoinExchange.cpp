#include "../inc/BitcoinExchange.hpp"
#include <ctime>
#include <exception>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() {
	databaseToMap();
}

void BitcoinExchange::databaseToMap() {
	std::ifstream database("data/data.csv");
	if(!database.is_open())
		throw std::runtime_error("error: could not open database");

	std::string line;
	if (!std::getline(database, line))
		throw std::runtime_error("error: database empty");
	if (line != "date,exchange_rate")
		throw std::runtime_error("error: invalid database");
	while (std::getline(database, line)) {
		size_t commaPos = line.find(',');
		std::string key = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1);
		_data[key] = std::stof(value);
	}
}

float BitcoinExchange::findRate(std::string& date) {
	auto it = _data.lower_bound(date);
	if (it != _data.end() && it->first == date)
		return it->second;
	if (it == _data.begin()) {
		std::cerr << C_R << "no earlier dates" << C_RST << std::endl;
		return -1;
	}
	--it;
	return it->second;
}

bool BitcoinExchange::validateDate(std::string& date) {
	std::tm tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");

	if (ss.fail() || !ss.eof()) {
		std::cerr << C_R << "bad date format(" << date << ")" << C_RST << std::endl;
		return false;
	}

	int day = tm.tm_mday;
	int mon = tm.tm_mon;
	std::mktime(&tm);

	if (tm.tm_mday != day || tm.tm_mon != mon) {
		std::cerr << C_R << "invalid date (" << date << ")" << C_RST << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::validateValue(std::string& valueStr) {
	float value;
	try {
		value = std::stof(valueStr);
	} catch (const std::exception&) {
		std::cerr << C_R << "invalid value (" << value << ")" << C_RST << std::endl;
		return false;
	}
	if (value < 0 || value > 1000) {
		std::cerr << C_R << "invalid value (" << value << ")" << C_RST << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::parseLine(std::string& line) {
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos) {
		std::cerr << C_R << "no '|' found" << C_RST << std::endl;
		return ;
	}
	std::string date = line.substr(0, pipePos);
	std::string value = line.substr(pipePos + 1);
	std::erase(date, ' ');
	std::erase(value, ' ');
	if (validateDate(date) && validateValue(value)) {
		float rate = findRate(date);
		if (rate < 0)
			return ;
		float result = std::stof(value) * rate;
		std::cout << C_G << date << " => " << result << C_RST << std::endl;
	}
}

void BitcoinExchange::processInput(std::string& filename) {
	std::ifstream txtFile(filename);
	if (!txtFile.is_open())
		throw std::runtime_error("error: could not open text file");

	std::string line;
	if (!std::getline(txtFile, line))
		throw std::runtime_error("error: text file empty");
	if (line != "date | value")
		throw std::runtime_error("error: invalid text file");
	while (std::getline(txtFile, line)) {
		parseLine(line);
	}
}
