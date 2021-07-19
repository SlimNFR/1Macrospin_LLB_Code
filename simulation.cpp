//---This is the simulation.cpp file. It defines the simulation.h functions.


//---Standard libraries
#include<fstream>
#include<iostream>
#include<cmath>

//---User-defined libraries
#include"simulation.h"
#include"solver.h"
#include"equation.h"
#include"field.h"
#include"input.h"
#include"particle.h"

//---Namespace simulation

namespace simulation{
	
//---Variables

double time;

//---Functions

int laser_induced_dynamcis(double mx_0, double my_0, double mz_0,
					   	   double &mx_n1, double &my_n1, double &mz_n1,
					   	   double &t,
					   	   int t_start, int t_end, int t_step, double timescale,
					   	   std::ofstream &f1)
{
	double REAL_T;
	double Bx_eff, By_eff, Bz_eff;
	double gamma, alpha_par, alpha_perp;
	double torque_mod;

	mx_n1 = mx_0;
	my_n1 = my_0;
	mz_n1 = mz_0;


	gamma=input::gamma; alpha_par=input::alpha_par; alpha_perp=input::alpha_perp;


	for(int t=t_start; t<=t_end; t=t+t_step)
	{	//loop time 
		REAL_T = t*timescale;

		f1<<REAL_T<<" "<<mx_n1<<" "<<my_n1<<" "<<mz_n1<<" "<<"\n";
	
		field::calculate(); //compute the field at each new step
		Bx_eff = field::Bx_eff; By_eff = field::By_eff; Bz_eff = field::Bz_eff; torque_mod=field::torque_mod;
		

		if(fabs(torque_mod)<1e-5)break;

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

int equilibrate_system(double mx_0, double my_0, double mz_0,
					   double &mx_n1, double &my_n1, double &mz_n1,
					   double &t,
					   int t_start, int t_end, int t_step, double timescale,
					   std::ofstream &f1)
{	
	double REAL_T;
	double Bx_eff, By_eff, Bz_eff;
	double gamma, alpha_par, alpha_perp;
	double torque_x, torque_y, torque_z,torque_mod;

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
		torque_x = (my_n1*Bz_eff - mz_n1*By_eff);
		torque_y = (mz_n1*Bx_eff - mx_n1*Bz_eff);
		torque_z = (mx_n1*By_eff - my_n1*Bx_eff);

		torque_mod = torque_x*torque_x+
					 torque_y*torque_y+
					 torque_z*torque_z;

		if(fabs(torque_mod)<1e-5)break;

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

