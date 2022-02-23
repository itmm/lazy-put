# Implementation of `lazy-put`

This file describes the contents of `lazy-put.cpp`. It consists of two parts:

```c++
int main(int argc, const char *argv[]) {
	// handle args
	// process input
}
```

The argument handling is easy. If there is one argument not equal to `--help`,
then it is a path. Otherwise the app prints a help message:

```c++
#include <cstdlib>
#include <string>

int main(int argc, const char *argv[]) {
	// handle args
	if (argc != 2 || argv[1] == std::string { "--help" }) {
		print_help();
		std::exit(EXIT_SUCCESS);
	}
	std::string path { argv[1] };
	// ...
}
```

The following function prints the help message:

```c++
#include <cstdlib>
#include <iostream>
#include <string>

static inline void print_help() {
	std::cout << "usage: lazy-put (--help | <file path>\n\n"
		"Copies standard input into <file path>. If the input\n"
		"is identical to the contents of <file path>, the file\n"
		"will not be modified: it keeps the same timestamp.n";
}

// ...
```

Now we only need to use the `Lazy_Write` class to copy the input into the
file that was specified as command line argument:

```c++
// ...
#include <string>
#include "lazy-write/lazy-write.h"
// ...
int main(int argc, const char *argv[]) {
	// ...
	// process input
	Lazy_Write out { path };
	std::string line;
	while (std::getline(std::cin, line)) {
		out << line << "\n";
	}
}
```

That is all. The program is complete.
