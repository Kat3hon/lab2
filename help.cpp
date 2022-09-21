#include "archSpiral.h"

void errList(int num) {
	char* err[] = {"Error! Incorrect value! Try again."};
	if (num < sizeof(errList)/sizeof(errList[0]))
		std::cout << err[num] << std::endl;
	else std::cout << "There is no that error in list." << std::endl;
	return;
}

void getDouble(double& value) {
	std::cin >> x;
	if (std::cin.fail())
		throw std::runtime_error("Error! Wrong type.");
	if (std::cin.eof())
		throw std::runtome_error("End of file! Breaking...");
	std::cin.ignore(std::numeric_limits<std:streamsize>::max(), '\n');
	return;
}

void setCurve(double& x, double& y, double& step) {
	std::cout << "Input the coordinates of point O:" << std::endl << std::endl;
	std::cout << "x-coordinate:" << std::endl;
	getDouble(x);
	std::cout << "y-coordinate:" << std::endl;
	getDouble(y);
	std::cout << "step of the curve:" << std::endl;
	getDouble(step);
	return;
}

void setRadius(double& r1, double& r2) {
	std::cout << "Input the first polar radius:" << std::endl;
	getDouble(r1);
	std::cout << "Input the second poler radius:" << std::endl;
	getDouble(r2);
	return;
}

void setStep(double value) {
	this->step = value;
	return;
}

double getStep() const {
	return this->step;
}

