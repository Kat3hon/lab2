#include "archSpiral.h"

double archSpiral::distanceToCentre(const double& angle) const {
	return angle*step/(2*pi);
}

double archSpiral::areaOfSector(const double& r1, const double& r2) const {
	if (r1 < 0 || r2 < 0)
		throw std::runtime_error("Polar radius can not be negative.");
	double diff = abs(r2-r1)/step;
	if (diff > 1)
		throw std::runtime_error("The angle between two polar radiuses can not be greater than 2*pi.");
	else {
		return (r1*r1 + r1*r2 + r2*r2)*diff*2*pi/6;
	}
}

double archSpiral::areaFigure(const int n) const {
	if (n < 0)
		throw std::runtime_error("Num of spiral turn can not be negative.");
	return step*step*(n*n*n - (n-1)*(n-1)*(n-1))*pi/3;
}

double archSpiral::areaCircle(const int n) const {
	if (n < 0)
		throw std::runtime_error("Num of spiral turn can not be negative.");
	return step*step*2*n*pi; 
}

double archSpiral::lenghtArc(const double& angle) const {
	return step*(angle*sqrt(1+angle*angle) + log(angle+sqrt(1+angle*angle)))/(2*2*pi);
}

double archSpiral::radiusOfCurvature(const double& angle) const {
	return step*pow((tan(angle)*tan(angle) + 1),3/2)/((1/(cos(angle)*cos(angle))+1)*2*pi);
}

void archSpiral::setStep(double value) {
	//step < 0 ?
	step = value;
	return;
}

double archSpiral::getStep() const {
	return step;
}

archSpiral::archSpiral() {
	step = 0;
}

archSpiral::~archSpiral() {
	step = 0;
}