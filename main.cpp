#include "archSpiral.h"

using namespace archSpiral;
int main() {
	std::cout << "Let's start!" << std::end << std::end;
	int rc;
	while (rc = dialog(msgs, Nmsgs))
		if(fptr[rc]())
			break;
	std::cout << "That is all! End..." << std::endl;
	return 0;						
}