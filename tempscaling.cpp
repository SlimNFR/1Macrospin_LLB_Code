//---This is the tempscaling.cpp file. It defines the tempscaling.h functions.


//---Standard libraries


//---User-defined libraries
#include"tempscaling.h"

//---Namespace tempscaling

namespace tempscaling{
	
//---Variables



//---Functions

int alpha_par_f(double T, double Tc, double lambda,double &alpha_par)
{	//calculates alpha_par at given T temperature

	alpha_par = (2.0/3.0)*(T/Tc)*lambda;
	return 0;

}
int alpha_perp_f(double T, double Tc, double lambda, double &alpha_perp)
{	//calculates alpha_perp at given T temperature
	
	alpha_perp = lambda*(1-(T/(3*Tc)));
	return 0;
}

}


//---End of tempscaling.cpp file.

