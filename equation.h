//---This is the equation.h file.
#pragma once

#ifndef EQUATION_H
#define EQUATION_H

//---Standard libraries


//---User-defined libraries


//---Namespace equation

namespace equation{
	
//---Variables


//---Functions
double CurieWeiss_f(double x, double T, double Tc, double eps);
double CurieWeiss_df(double x, double T, double Tc, double eps);
double Langevin_df(double T, double Tc, double eps, double m_e);


}

#endif
//---End of equation.h file.