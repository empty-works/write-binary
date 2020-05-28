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
	if(!output_file) {
		std::cout << "Error opening file." << std::endl;
		return 1;
	}

	Person someone {"Henry", 32};
	output_file.write(reinterpret_cast<char *>(&someone), sizeof(Person));
	output_file.close();	

	// Read from binary file.
	std::ifstream input_file;
	input_file.open(file_name, std::ios::binary);
	if(!input_file) {
		std::cout << "Error opening file." << std::endl;
		return 1;
	}

	Person someone_cool {};
	input_file.read(reinterpret_cast<char *>(&someone_cool), sizeof(Person));
	std::cout << "Someone cool " << someone_cool.name << " " << someone_cool.age << std::endl;
	input_file.close();	
		
	return 0;
}
