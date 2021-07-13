//---This is the dynamics.cpp file. It defines the dynamics.h functions.


//---Standard libraries
#include<cmath>
#include<iostream>

//---User-defined libraries
#include"dynamics.h"

//---Namespace dynamics

namespace dynamics{
	
//---Variables
double fx, fy, fz = 0.0;


//---Functions
int LLB_equation(double mx, double my, double mz,
				 double Bx_eff, double By_eff, double Bz_eff,
				 double gamma, double alpha_par, double alpha_perp,
				 double &fx,double &fy,double &fz)
{
	//sets up the LLB equation

	//Temporary variables
	double m_squared = mx*mx + my*my + mz*mz;
	double mTimesB = mx*Bx_eff + my*By_eff + mz*Bz_eff;
	double C1 = gamma*alpha_par/m_squared;
	double C2 = gamma*alpha_perp/m_squared;
	

	//std::cout<<"|gamma: "<<gamma<<"|alpha_par: "<<alpha_par<<"|alpha_perp: "<<alpha_perp<<"\n";
		std::cout<<"Bx_eff: "<<Bx_eff<<"|By_eff: "<<By_eff<<"|Bz_eff: "<<Bz_eff
		<<"|mx: "<<mx<<"|my: "<<my<<"|mz: "<<mz<<"\n";

	fx = +gamma*(By_eff*mz - my*Bz_eff) + C1*(mx*Bx_eff)*mx + C2*(Bx_eff*m_squared - mx*mTimesB);
	fy = -gamma*(Bx_eff*mz - mx*Bz_eff) + C1*(my*By_eff)*my + C2*(By_eff*m_squared - my*mTimesB);
	fz = +gamma*(Bx_eff*my - mx*By_eff) + C1*(mz*Bz_eff)*mz + C2*(Bz_eff*m_squared - mz*mTimesB);

	
	std::cout<<"Bx_eff: "<<Bx_eff<<"|By_eff: "<<By_eff<<"|Bz_eff: "<<Bz_eff
		<<"|mx: "<<mx<<"|my: "<<my<<"|mz: "<<mz<<"\n";
	
	//std::cout<<"|fx: "<<fx<<"|fy: "<<fy<<"|fz: "<<fz<<"\n";

	return 0;
}

}


//---End of dynamics.cpp file.

