#include "archSpiral.h"

int dialog::dialog(const char* msgs[], int N) {
	int rc;
	do {
		for (int i = 0; i < N; ++i)
			std::cout << msgs[i] << std::endl;
		std::cout << std::endl;
		try {
			io::getType(rc);
		}
		catch(const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			return 0;
		}
	} while (rc < 0 || rc >= N);
	return rc;
}

int dialog::change(ArchimedeanSpiral& spiral) {
	std::cout << "Input step of the spiral:" << std::endl;
	double step;
	try {
		io::getType(step);
	}
	catch(const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	spiral.setStep(step);
	std::cout << "Here is your curve:" << std::endl << std::endl;
	dialog::show(spiral);
	return 0;
}

int dialog::centre(ArchimedeanSpiral& spiral) {
	std::cout << "Input the angle (in radians):" << std::endl;
	double angle;
	try {
		io::getType(angle);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The distance is " << spiral.distanceToCentre(angle) << " ." << std::endl;
	return 0;
}

int dialog::sector(ArchimedeanSpiral& spiral) {
	double r1, r2;
	try {
		io::radius(r1, r2);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The area is " << spiral.areaOfSector(r1, r2) << " ." << std::endl;
	return 0;
}

int dialog::figure(ArchimedeanSpiral& spiral) {
	std::cout << "Input the number of spiral turn:" << std::endl;
	double n;
	try {
		io::getType(n);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The area is " << spiral.areaFigure(n) << " ." << std::endl;
	return 0;
}

int dialog::circle(ArchimedeanSpiral& spiral) {
	std::cout << "Input the number of circle:" << std::endl;
	double n;
	try {
		io::getType(n);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}	
	std::cout << "The area is " << spiral.areaCircle(n) << " ." << std::endl;
	return 0;
}

int dialog::arc(ArchimedeanSpiral& spiral) {
	std::cout << "Input the angle (in radians):" << std::endl;
	double angle;
	try {
		io::getType(angle);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The lenght of arc is" << spiral.lenghtArc(angle) << " ." << std::endl;
	return 0;
}

int dialog::radius(ArchimedeanSpiral& spiral) {
	std::cout << "Input the angle (in radians):" << std::endl;
	double angle;
	try {
		io::getType(angle);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "The radius is " << spiral.radiusOfCurvature(angle) << " ." << std::endl;
	return 0;
}

int dialog::show(ArchimedeanSpiral& spiral) {
	std::cout << "nothing" << std::endl;
	return 0;
}