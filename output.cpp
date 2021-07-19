//---This is the output.cpp file. It defines the output.h functions.


//---Standard libraries
#include<fstream>
#include<iostream>

//---User-defined libraries
#include"output.h"
#include"input.h"

//---Namespace output

namespace output{
	
//---Variables
std::ofstream file_NR, file_interpol;
std::ofstream file_chi_vs_T;
std::ofstream file_K_vs_T;
std::ofstream file_magn_vs_time_equilibrate;

//---Functions
int open_files_to_write()
{

	if(input::m_vs_T_curve == true)
	{
		output::file_NR.open("output_NR.txt", std::ofstream::out);
		output::file_interpol.open("output_interpol.txt", std::ofstream::out);
	}

	if(input::chipar_vs_T_curve == true)
	{
		output::file_chi_vs_T.open("output_chi_vs_T.txt", std::ofstream::out);
	}

	if(input::K_vs_T_curve == true)
	{
		output::file_K_vs_T.open("output_K_vs_T.txt", std::ofstream::out);
	}

	if(input::equilibrate == true)
	{

		output::file_magn_vs_time_equilibrate.open("output_MvsT_equilibrate.txt", std::ofstream::out);	

	}



	return 0;
}

int close_files()
{

	if(input::m_vs_T_curve == true)
	{
		output::file_NR.close();
		output::file_interpol.close();
	}

	if(input::chipar_vs_T_curve == true)
	{
		output::file_chi_vs_T.close();
	}

	if(input::K_vs_T_curve == true)
	{
		output::file_K_vs_T.close();
	}


	if(input::equilibrate == true)
	{

		output::file_magn_vs_time_equilibrate.close();

	}

	return 0;

}

}


//---End of output.cpp file.

