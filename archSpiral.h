#include <iostream>
#include <cmath>

namespace archSpiral{
	class archSpiral {
		private:
			//coordinates of point O
			//double x;
			//double y;

			//step of spiral
			double step;

			//menu
			const char* msgs[] = {"\n0.Quit", "1.Change curve", 
			"2.Lenght from centre to your point", "3.Area of sector", 
			"4.Area of figure in n-th spiral", "5.Area of n-th circle", 
			"6.Lenght of arc", "7.Radius of curvature", "8.Show curve"};
			const int Nmsgs = sizeof(msgs)/sizeof(msgs[0]);
			int (*fptr[])() = {nullptr, D_change, D_centre, D_sector, 
							D_figure, D_circle, D_arc, D_radius, D_show};
			int dialog(const char*, int);

		public:

			archSpiral():step = 0; //constructor
			//archSpiral(const archSpiral &); //copy constructor

			~archSpiral(); //destructor

			std::ostream & print (std::ostream &) const;

			//double getCoordinate() const; //select coordinate
			//void selCoordinate(double);	//modify coordinate
			double getStep() const; //select step
			void setStep(double);	//modify step

			//dialog functions
			D_change();
			D_centre();
			D_sector();
			D_figure();
			D_circle();
			D_arc();
			D_radius();
			D_show();

	};		

};