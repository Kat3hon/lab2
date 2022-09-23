#include "archSpiral.h"

int main() {
	std::cout << "Let's start!" << std::endl << std::endl;
	int rc;
	ArchimedeanSpiral curve;
	const char* msgs[] = {"\n0.Quit", "1.Change curve", 
			"2.Lenght from centre to your point", "3.Area of sector", 
			"4.Area of figure in n-th spiral", "5.Area of n-th circle", 
			"6.Lenght of arc", "7.Radius of curvature", "8.Show curve"};
	const int Nmsgs = sizeof(msgs)/sizeof(msgs[0]);
	int (*fptr[])(ArchimedeanSpiral&) = {nullptr, dialog::change, dialog::centre, dialog::sector, 
									dialog::figure, dialog::circle, dialog::arc, dialog::radius, dialog::show};
	while (rc = dialog::dialog(msgs, Nmsgs))
		if(fptr[rc](curve))
			break;
	std::cout << "That is all! End..." << std::endl;
	return 0;						
}