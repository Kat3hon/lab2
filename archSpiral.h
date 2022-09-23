#include <iostream>
#include <cmath>
#include <limits>
#define pi 3.14

class archSpiral {
	private:
		double step; //step of spiral
	public:

		archSpiral(); //constructor
		~archSpiral(); //destructor

		double getStep() const; //select step
		void setStep(double value);	//modify step

		double distanceToCentre(const double& angle) const;
		double areaOfSector(const double& radius1, const double& radius2) const;
		//integral firure and circle
		double areaFigure(const int num) const; 
		double areaCircle(const int num) const;
		double lenghtArc(const double& angle) const;
		double radiusOfCurvature(const double& angle) const;
};

namespace dialog {
	int change(archSpiral&);
	int centre(archSpiral&);
	int sector(archSpiral&);
	int figure(archSpiral&);
	int circle(archSpiral&);
	int arc(archSpiral&);
	int radius(archSpiral&);
	int show(archSpiral&);

	int dialog(const char* msgs[], int Nmsgs);
};

namespace io {
	void getType(int& value);
	void getType(double& value);
	void radius(double& radius1, double& radius2);
};