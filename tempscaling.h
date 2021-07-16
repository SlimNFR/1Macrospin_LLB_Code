//---This is the tempscaling.h file.
#pragma once

#ifndef TEMPSCALING_H
#define TEMPSCALING_H

//---Standard libraries
#include<iostream>
#include<fstream>

//---User-defined libraries


//---Namespace tempscaling

namespace tempscaling{
	
//---Variables
extern bool m_vs_T_curve;

//---Functions
//instantaneous parameters
int alpha_par_f(double T, double Tc, double lambda,double &alpha_par);
int alpha_perp_f(double T, double Tc, double lambda, double &alpha_perp);
int equilibrium_magn_f();

//equilibrium curves
int m_vs_T_curve_f(double Tc, double eps, std::ofstream &f1, std::ofstream &f2);


}

#endif
//---End of tempscaling.h file.