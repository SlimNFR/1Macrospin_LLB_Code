//---This is the equation.cpp file. It defines the equation.h functions.


//---Standard libraries
#include<cmath>

//---User-defined libraries
#include"equation.h"


//---Namespace equation

namespace equation{
	
//---Variables



//---Functions
double CurieWeiss_f(double x, double T, double Tc, double eps)
{//This is the Curie Weiss self consistent equation
    return ( (eps/3.0)*(T/Tc)*x - 1.0/(tanh(x)) + 1.0/x );
}
double CurieWeiss_df(double x, double T, double Tc, double eps)
{//The derivative of the Curie Weiss equation
    return ( (eps/3.0)*(T/Tc)  + pow( (1.0/sinh(x)),2.0 ) - 1.0/(x*x)  );
}

}


//---End of equation.cpp file.

