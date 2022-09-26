#include <iostream>
#include <cmath>
#include <limits>
#include <numbers>

class ArchimedeanSpiral {
	private:
		constexpr static double PI = std::numbers::pi_v<double>;
		constexpr static double delta = 0.001;
		double radian_step; //step of spiral

	public:
		constexpr explicit ArchimedeanSpiral(double value):	radian_step(value) {
			if (value == 0)
				throw std::invalid_argument("Invalid coefficient");	
		}

		constexpr ~ArchimedeanSpiral() {
			radian_step = 0;
		}

		constexpr ArchimedeanSpiral& setRadianStep(double value) {
			if (value == 0)
				throw std::invalid_argument("Invalid coefficient");
			radian_step = value;
			return *this;
		} 

		constexpr double distanceToCentre(const double& angle) const {
			if (angle < 0)
				throw std::invalid_argument("Negative angle");
			return angle*radian_step/(2*PI);
		}		

		constexpr double areaOfSector(const double& radius1, const double& radius2) const {
			if (radius1 < 0 || radius2 < 0)
				throw std::invalid_argument("Negative polar radius");
			double difference = abs(radius2-radius1)/radian_step;
			if (difference > 1)
				throw std::invalid_argument("The angle between two polar radiuses is greater thar 2*PI");
			else return (radius1*radius1 + radius1*radius2 + radius2*radius2)*difference*2*PI/6;
		}

		constexpr double integral(const double& angle, const double& radius) const {
			if (angle < 0)
				throw std::invalid_argument("Negative angle");
			if (radius < 0) 
				throw std::invalid_argument("Negative radius");
			double result = 0;
			for (double start = delta; start < angle; start += delta) {
				result += start*pow(radius, 2);
			}
			return result/2;	
		}

		constexpr double integral(const int& num) const {
			if (num <= 0) 
				throw std::invalid_argument("Invalid coefficient");
			double result = 0;
			for (double start = delta; start < 2*PI; start += delta) {
				result += start*pow(radian_step*num, 2);
			}
			return result/2;	
		}

		constexpr double areaOfSectorIntegral(const double& radius1, const double& radius2) const {
			if (radius1 < 0 || radius2 < 0)
				throw std::invalid_argument("Negative polar radius");
			double difference = abs(radius2-radius1)/radian_step;
			if (difference > 1)
				throw std::invalid_argument("The angle between two polar radiuses is greater thar 2*PI");
			double angle = difference*2*PI;
			return (this->integral(angle, radius1) + this->integral(angle, radius2) + this->integral(angle, sqrt(radius1*radius2)))/3;

		}

		constexpr double areaFigure(const int& numTurn) const {
			if (numTurn <= 0)
				throw std::invalid_argument("Invalid coefficient");
			return radian_step*radian_step*(numTurn*numTurn*numTurn - (numTurn-1)*(numTurn-1)*(numTurn-1))*PI/3;

		}

		constexpr double areaFigureIntegral(const int& numTurn) const {
			if (numTurn <= 0)
				throw std::invalid_argument("Invalid coefficient");
			return (pow(numTurn, 3) - pow(numTurn - 1, 3)*(this->integral(numTurn)))/(3*pow(numTurn, 2));			
		}

		constexpr double areaCircle(const int& numCircle) const {
			if (numCircle <= 0)
				throw std::invalid_argument("Invalid coefficient");
			return pow(radian_step,2)*2*numCircle*PI; 
		}

		constexpr double areaCircleIntegral(const int& numCircle) const {
			if (numCircle <= 0)
				throw std::invalid_argument("Invalid coefficient");
			return this->integral(numCircle);
		}

		constexpr double lenghtArc(const double& angle) const {
			if (angle < 0)
				throw std::invalid_argument("Negative angle");
			return radian_step*((angle*sqrt(1+pow(angle,2))) + log(angle+sqrt(1+pow(angle,2))))/(2*2*PI);
		}

		constexpr double radiusOfCurvature(const double& angle) const {
			if (angle < 0)
				throw std::invalid_argument("Negative angle");
			return radian_step*pow((tan(angle)*tan(angle) + 1),3/2)/((1/(cos(angle)*cos(angle))+1)*2*PI);
		}
};

namespace dialog {
	int change(ArchimedeanSpiral&);
	int distanceToCentre(ArchimedeanSpiral&);
	int areaOfSector(ArchimedeanSpiral&);
	int areaFigure(ArchimedeanSpiral&);
	int areaCircle(ArchimedeanSpiral&);
	int lenghtArc(ArchimedeanSpiral&);
	int radiusOfCurvature(ArchimedeanSpiral&);

	int dialog(const char* msgs[], int Nmsgs);
};

namespace io {
	void getType(int& value);
	void getType(double& value);
	void setRadiuses(double& radius1, double& radius2);
};