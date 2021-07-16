//---This is the tempscaling.cpp file. It defines the tempscaling.h functions.


//---Standard libraries
#include<fstream>
#include<iostream>

//---User-defined libraries
#include"tempscaling.h"
#include"rootfind.h"
#include"interpolate.h"
#include"equation.h"
#include"input.h"

//---Namespace tempscaling

namespace tempscaling{
	
//---Variables
bool m_vs_T_curve = true;


//---Functions

int alpha_par_f(double T, double Tc, double lambda,double &alpha_par)
{	//calculates alpha_par at given temperature T

	alpha_par = (2.0/3.0)*(T/Tc)*lambda;
	return 0;

}
int alpha_perp_f(double T, double Tc, double lambda, double &alpha_perp)
{	//calculates alpha_perp at given temperature T
	
	alpha_perp = lambda*(1-(T/(3*Tc)));
	return 0;
}


int equilibrium_magn_f()
{	//calculates the equilibrium magnetisation for a given temperature T


	return 0;
}

int m_vs_T_curve_f(double Tc, double eps, std::ofstream &f1, std::ofstream &f2)
{	//Calculates the whole m_e(T) curve.
	int T;
	double m_e;

	// Up to T=Tc-nearTc, I will solve the Curie Weiss equation in steps of broad_step_T.
	// For T>Tc - nearTc I use discrete_step_T.
	int broad_step_T=50;
	int discrete_step_T=1;
	int nearTc=50; 

	//Variables to be used for the NR algorithm //To do later: Initialise these from a txt file.
	//N_iter, x0 and TOL are initialised in the rootfind.cpp file
	//eps is initialised in the input.cpp file

	//For my given temperature range, call the NR algorithm and solve the Curie-Weiss equation.
	for(T=0;T<=Tc;T++)
	{
	        if(T==0 || T==Tc)
	        {//The NR algorithm will not work for T=0 or T=Tc.

	                cubicspline::x_interpol.push_back(T);
	                if(T==0){m_e=1.0; cubicspline::y_interpol.push_back(m_e);}
	                if(T==Tc){m_e=0.0; cubicspline::y_interpol.push_back(m_e);}

	                f1<<T<<" "<<m_e<<"\n";
	        }

	    else
	    {
	            if(T<=Tc-nearTc && T%broad_step_T == 0){

	                m_e=rootfind::NewtonRaphson(equation::CurieWeiss_f,equation::CurieWeiss_df,
	                							rootfind::x0,rootfind::TOL,rootfind::N_iter,eps,T,Tc);
	                cubicspline::x_interpol.push_back(T);
	                cubicspline::y_interpol.push_back(m_e);
	                f1<<T<<" "<<m_e<<"\n";
	                //std::cout<<"x and y: "<<cubicspline::x_interpol.back()<<" "<<cubicspline::y_interpol.back()<<"\n";

	            }

	            else if (T>Tc-nearTc && T%discrete_step_T == 0){
	                m_e=rootfind::NewtonRaphson(equation::CurieWeiss_f,equation::CurieWeiss_df,
	                							rootfind::x0,rootfind::TOL,rootfind::N_iter,eps,T,Tc);
	                cubicspline::x_interpol.push_back(T);
	                cubicspline::y_interpol.push_back(m_e);
	                f1<<T<<" "<<m_e<<"\n";
	                //std::cout<<"x and y: "<<cubicspline::x_interpol.back()<<" "<<cubicspline::y_interpol.back()<<"\n";
	            }
	        }

	}

	//Interpolate the x_interpol,y_interpol data points via the Cubic spline algorithm to find the whole m_e(T) curve.

	int n = cubicspline::x_interpol.size(); //This will set the dimensions of my coefficient arrays b,c,d. 
	int id; //This will store the interval id of each new x value (temperature value).
	n--;

	cubicspline::b.resize(n);
	cubicspline::c.resize(n+1);
	cubicspline::d.resize(n);

	cubicspline::interpolate(n,cubicspline::x_interpol,cubicspline::y_interpol,cubicspline::b,cubicspline::c,cubicspline::d);

	
	for (T = 0; T <=631; T++)
	{
	    cubicspline::get_xinterval_id(cubicspline::x_interpol, T, id);
	    //std::cout<<T<<" "<<cubicspline::y_interpol[id]<<" "<<cubicspline::b[id]<<" "<<cubicspline::c[id]<<" "<<cubicspline::d[id]<<"\n";
	    f2<<T<<" "<<cubicspline::polynome(cubicspline::y_interpol[id],cubicspline::b[id],cubicspline::c[id],cubicspline::d[id],T,cubicspline::x_interpol[id])<<"\n";
	}

	f1.close();
	f2.close();






	return 0;
}

}


//---End of tempscaling.cpp file.

