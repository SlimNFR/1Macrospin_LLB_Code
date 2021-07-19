//---This is the init.cpp file. It defines the init.h functions.


//---Standard libraries


//---User-defined libraries
#include"init.h"
#include"tempscaling.h"
#include"input.h"
#include"output.h"
#include"simulation.h"
#include"particle.h"

//---Namespace init

namespace init{
	
//---Variables



//---Functions
int parameters()
{	//This function will initialise my simulation parameters

	tempscaling::internal::obtain_interpolation_polynome_mVsT_data(); //initialise me_vs_T interpolation function
	return 0;
}

int files()
{// This function will create all the required output files

	output::open_files_to_write();

	return 0;
}

int sim()
{//This function will initialise the chosen simulation

	if(input::m_vs_T_curve==true)
	{
		tempscaling::internal::call_mVsT_sim();
	}

	if(input::chipar_vs_T_curve==true)
	{
		tempscaling::internal::call_chiparVsT_sim();
	}

	if(input::K_vs_T_curve==true)
	{

		tempscaling::internal::call_KVsT_sim();
	}

	if(input::equilibrate==true)
	{
		tempscaling::internal::calc_parameters_at_T();
		simulation::equilibrate_system(input::mx_0, input::my_0, input::mz_0,
									   particle::mx, particle::my, particle::mz,
									   simulation::time,
							   		   input::t_min_equil, input::t_max_equil, input::delta_t_equil, input::timescale_equil, 
							   		   output::file_magn_vs_time_equilibrate);

	}

	return 0;
	
}



}


namespace init{


	namespace internal{
		int run()
		{//This function will run the code

			init::parameters();
			init::files();
			init:sim();
			return 0;
		}	
	}
}


//---End of init.cpp file.

