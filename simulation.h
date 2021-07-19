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


//---Functions
int equilibrate_system(double mx_0, double my_0, double mz_0,
					   int t_start, int t_end, int t_step, double timescale, std::ofstream &f1);

}

#endif
//---End of simulation.h file.