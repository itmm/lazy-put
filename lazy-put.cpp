#line 16 "lazy-put.md"
#include <cstdlib>
#line 34
#include <iostream>
#line 17
#include <string>
#line 53
#include "lazy-write/lazy-write.h"
#line 18

#line 37
static inline void print_help() {
	std::cout << "usage: lazy-put (--help | <file path>\n\n"
		"Copies standard input into <file path>. If the input\n"
		"is identical to the contents of <file path>, the file\n"
		"will not be modified: it keeps the same timestamp.n";
}

#line 6
int main(int argc, const char *argv[]) {
	// handle args
#line 21
	if (argc != 2 || argv[1] == std::string { "--help" }) {
		print_help();
		std::exit(EXIT_SUCCESS);
	}
	std::string path { argv[1] };
#line 8
	// process input
#line 58
	Lazy_Write out { path };
	std::string line;
	while (std::getline(std::cin, line)) {
		out << line << "\n";
	}
#line 9
}
