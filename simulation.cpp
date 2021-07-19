//---This is the simulation.cpp file. It defines the simulation.h functions.


//---Standard libraries
#include<fstream>
#include<iostream>

//---User-defined libraries
#include"simulation.h"
#include"solver.h"
#include"equation.h"
#include"field.h"
#include"input.h"

//---Namespace simulation

namespace simulation{
	
//---Variables



//---Functions
int equilibrate_system(double mx_0, double my_0, double mz_0,
					   int t_start, int t_end, int t_step, double timescale, std::ofstream &f1)
{	
	double mx_n1, my_n1, mz_n1;
	double REAL_T;
	double Bx_eff, By_eff, Bz_eff;
	double gamma, alpha_par, alpha_perp;
	

	mx_n1 = mx_0;
	my_n1 = my_0;
	mz_n1 = mz_0;


	gamma=input::gamma; alpha_par=input::alpha_par; alpha_perp=input::alpha_perp;

	for(int t=t_start; t<=t_end; t=t+t_step)
	{	//loop time 
		REAL_T = t*timescale;

		f1<<REAL_T<<" "<<mx_n1<<" "<<my_n1<<" "<<mz_n1<<" "<<"\n";
	
		field::calculate(); //compute the field at each new step
		Bx_eff = field::Bx_eff; By_eff = field::By_eff; Bz_eff = field::Bz_eff;
		solver::heun_scheme_step(equation::LLB_classic,
								 mx_0,my_0,mz_0,
								 gamma, alpha_par, alpha_perp,
								 t_step, timescale,
								 Bx_eff,By_eff,Bz_eff,
								 mx_n1, my_n1, mz_n1); //get next magnetisation value

		mx_0 = mx_n1;
		my_0 = my_n1;
		mz_0 = mz_n1;


	}
	
	return 0;
}

}


//---End of simulation.cpp file.

