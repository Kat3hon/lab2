#include "archSpiral.h"

void io::getType(int& value) {
	std::cin >> value;
	if (std::cin.fail())
		throw std::runtime_error("Error! Wrong type.");
	if (std::cin.eof())
		throw std::runtime_error("End of file! Breaking...");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return;
}

void io::getType(double& value) {
	std::cin >> value;
	if (std::cin.fail())
		throw std::runtime_error("Error! Wrong type.");
	if (std::cin.eof())
		throw std::runtime_error("End of file! Breaking...");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return;
}

void io::radius(double& r1, double& r2) {
	std::cout << "Input the first polar radius:" << std::endl;
	io::getType(r1);
	std::cout << "Input the second poler radius:" << std::endl;
	io::getType(r2);
	return;
}
