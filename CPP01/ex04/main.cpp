#include <string>
#include <fstream>
#include <iostream>

std::string search_and_replace(const std::string& line, const std::string& search, const std::string& replace) {
	std::string result;
	size_t pos = 0;
	size_t found;
	while ((found = line.find(search, pos)) != std::string::npos) {
		result.append(line, pos, found - pos);
		result.append(replace);
		pos = found + search.length();
	}
	result.append(line, pos, std::string::npos);
	
	return result;
}

bool replace_strings(const std::string& filename, const std::string& search, const std::string& replace) {
	std::ifstream in(filename);
	if (!in) {
		std::cerr << "error: could not open " << filename << std::endl;
		return false;
	}
	std::string newFile = filename + ".replace";
	
	std::ofstream outFile(newFile);
	if (!outFile.is_open()) {
		std::cerr << "error: could not open " << newFile << " for writing" << std::endl;
		return false;
	}

	std::string line;
	while (getline(in, line)) {
		line = search_and_replace(line, search, replace);
		outFile << line << "\n";
	}
	outFile.close();
	return true;
}

int main(int ac, char** av) {
	if (ac != 4) {
		std::cerr << "error: usage: ./sedLoser <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string search = av[2];
	std::string replace = av[3];
	if (search.empty()) {
		std::cerr << "error: search string cannot be empty" << std::endl;
		return 1;
	}
	if (!replace_strings(filename, search, replace))
		return 1;
}
