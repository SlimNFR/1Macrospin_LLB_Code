//---This is the output.cpp file. It defines the output.h functions.


//---Standard libraries
#include<fstream>
#include<iostream>

//---User-defined libraries
#include"output.h"
#include"tempscaling.h"

//---Namespace output

namespace output{
	
//---Variables
std::ofstream file_NR, file_interpol;


//---Functions
int open_files_to_write()
{

	if(tempscaling::m_vs_T_curve == true)
	{
		output::file_NR.open("output_NR.txt", std::ofstream::out);
		output::file_interpol.open("output_interpol.txt", std::ofstream::out);
	}

	
	return 0;
}

}


//---End of output.cpp file.

