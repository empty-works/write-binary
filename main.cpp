#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::string file_name {"test.bin"};
	struct Person {
		std::string name;
		int age;
	};

	// Write to binary file.
	std::ofstream output_file;
	output_file.open(file_name, std::ios::binary);
	return 0;
}
