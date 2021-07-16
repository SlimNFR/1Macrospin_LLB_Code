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

//---Functions
int open_files_to_write();

}

#endif
//---End of output.h file.