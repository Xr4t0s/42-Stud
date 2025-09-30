#include <iostream>
#include <fstream>

std::string replace(std::string src, std::string s1, std::string s2) {
	std::string	ret;
	size_t pos;
	size_t start = 0;
	
	while ((pos = src.find(s1, start)) != std::string::npos) {
		ret.append(src.substr(start, pos - start));
		ret.append(s2);
		start = pos + s1.length();
	}
	ret.append(src.substr(start));
	
	return ret;
}

int main(int ac, char* av[]) {
	if (ac != 4) return 0;
	
	std::ifstream buff(av[1]);
	if ( !buff.is_open() ) { std::cerr << "error" << std::endl; return 0; }
	
	std::string arg = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if ( s1.length() == 0 || s2.length() == 0 ) { return 0; }
	
	std::ofstream out(arg.append(".replace").c_str());
	if ( !out.is_open() ) { return 0; }

	std::string line;
	while (std::getline(buff, line)) {
		line = replace(line, s1, s2);
		out << line << std::endl;
	}
	return 1;
}