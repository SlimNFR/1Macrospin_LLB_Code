//---This is the output.h file.
#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

//---Standard libraries
#include<fstream>
#include<iostream>

//---User-defined libraries


//---Namespace output

namespace output{
	
//---Variables
extern std::ofstream file_NR, file_interpol; 
extern std::ofstream file_chi_vs_T;
extern std::ofstream file_K_vs_T;
extern std::ofstream file_magn_vs_time_equilibrate;
//---Functions
int open_files_to_write();
int close_files();

}

#endif
//---End of output.h file.