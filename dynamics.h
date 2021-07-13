//---This is the dynamics.h file.
#pragma once

#ifndef DYNAMICS_H
#define DYNAMICS_H

//---Standard libraries


//---User-defined libraries


//---Namespace dynamics

namespace dynamics{
	
//---Variables
extern double fx, fy, fz;//These variables hold the left-hand side value of the LLB equation on all 3 dimensions.


//---Functions
int LLB_equation(double mx, double my, double mz,
				 double Bx_eff, double By_eff, double Bz_eff,
				 double gamma, double alpha_par, double alpha_perp,
				 double &fx,double &fy,double &fz);


}

#endif
//---End of dynamics.h file.