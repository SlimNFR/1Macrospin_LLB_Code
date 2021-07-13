//---This is the solver.h file.
#pragma once

#ifndef SOLVER_H
#define SOLVER_H

//---Standard libraries


//---User-defined libraries


//---Namespace solver

namespace solver{
	
//---Variables
extern int sim_time;

//---Functions
int heun_scheme(int (*dfunc)(double, double, double,
				double, double, double ,
				double, double, double,
				double &,double &,double &),
				double mx_0,double my_0, double mz_0,
				double gamma, double alpha_par, double alpha_perp,
				int t_min, int t_max, int delta_t,
				double &Bx_eff, double &By_eff, double &Bz_eff,
				int &t, double &mx_n1, double &my_n1, double &mz_n1);

}

#endif
//---End of solver.h file.