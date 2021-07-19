//---This is the simulation.h file.
#pragma once

#ifndef SIMULATION_H
#define SIMULATION_H

//---Standard libraries
#include<fstream>

//---User-defined libraries


//---Namespace simulation

namespace simulation{
	
//---Variables

extern double time;

//---Functions
int equilibrate_system(double mx_0, double my_0, double mz_0,
					   double &mx_n1, double &my_n1, double &mz_n1,
					   double &t,
					   int t_start, int t_end, int t_step, double timescale,
					   std::ofstream &f1);

}

#endif
//---End of simulation.h file.