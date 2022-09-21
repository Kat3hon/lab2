#include "archSpiral.h"
using namespace archSpiral;

int dialog(const char* msgs[], int N) {
	int rc;
	do {
		for (int i = 0; i < N; ++i)
			std::cout << msgs[i] << std::endl;
		std::cout << std::endl;
		try {
			getInt(rc);
		}
		catch(const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			return 0;
		}
	} while (rc < 0 || rc >= N);
	return rc;
}

int D_change(archSpiral& spiral) {
	/*double x, y, step;
	try {
		setCurve(x, y, step);
	}
	catch(const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	setX();
	setY();
	setStep();*/
	double step;
	try {
		getDouble(step);
	}
	catch(const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	setStep();
	std::cout << "Here is your curve:" << std::endl << std::endl;
	D_show(spiral);
	return 0;
}

int D_centre(const archSpiral& spiral) {
	std::cout << "Input the angle (in radians):" << std::endl;
	double angle;
	try {
		getDouble(angle);
	}
	catch (const std::exception& ex) {
		std:;cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The distance is " << angle*spiral.getStep()/(2*pi) << " ." << std::endl;
	return 0;
}

int D_sector(const archSpiral& spiral) {
	try {
		setRadius(r1, r2);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	double diff = mod(r2-r1)/step;
	if (diff > 1)
		std::cout << "The angle between this point is too big. Try again." << std::endl;
	else {
		std::cout << "The area is " << (r1*r1 + r1*r2 + r2*r2)*diff*2*pi/6 << " ." << std.endl;
	}
	return 0;
}

int D_figure(const archSpiral& spiral) {
	std::cout << "Input the number of spiral turn:" << std::endl;
	double n;
	char* msg = "";
	do {
		std::cout << msg << std::endl;
		msg = "Error! Wrong value! Try again.";
		try {
			getDouble(n);
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			return 1;
		}
	} while (n <= 0);	

	std::cout << "The area is " << spiral.getStep()*spiral.getStep()*(n*n*n - (n-1)*(n-1)*(n-1))*pi/3 << " ." << std::endl;
	return 0;
}

int D_circle(const archSpiral& spiral) {
	std::cout << "Input the number of circle:" << std::endl;
	double n;
	char* msg = "";
	do {
		std::cout << msg << std::endl;
		msg = "Error! Wrong value! Try again.";
		try {
			getDouble(n);
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			return 1;
		}
	} while (n <= 0);	

	std::cout << "The area is " << spiral.getStep()*spiral.getStep()*2*n*pi << " ." << std::endl;
	return 0;
}

int D_arc(const archSpiral& spital) {
	std::cout << "Input the angle (in radians):" << std::endl;
	double angle;
	try {
		getDouble(angle);
	}
	catch (const std::exception& ex) {
		std:;cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The lenght of arc is" << spiral.getStep()*(angle*sqrt(1+angle*angle) + ln(angle+sqrt(1+angle*angle)))/(2*2*pi) << " ." << std::endl;
	return 0;
}

int D_radius(const archSpiral& spiral) {
	std::cout << "Input the angle (in radians):" << std::endl;
	double angle;
	try {
		getDouble(angle);
	}
	catch (const std::exception& ex) {
		std:;cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The radius is " << spiral.getStep()*pow((tg(angle)*tg(angle) + 1),3/2)/((sec(angle)*sec(angle)+1)*2*pi) << " ." << std::endl;
	return 0;
}

int D_show(const archSpiral& spiral) {
	std::cout << "nothing" << std::endl;
	return 0;
}
