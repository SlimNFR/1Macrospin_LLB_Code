//---This is the input.h file.
#pragma once

#ifndef INPUT_H
#define INPUT_H

//---Standard libraries
#include<cmath>

//---User-defined libraries


//---Namespace input

namespace input{
	
//---Global constants
const double mu0=4.0*M_PI*1e-7; //Vacuum permeability: [H/m]
const double gamma = 1.76*1e11; // Gyromagnetic ratio: [rad/(s*T)]


//---Material parameters (Ni)
const double a = 0.35*1e-9; // Lattice spacing: [m]
const double Tc = 631.0; // Curie temperature: [K]
const double Ms_CGS = 500.0; // Saturation magnetisation: [emu/cc]
const double K_CGS = 5.3*1e4; // Magnetocrystlline first-order anis. constant: [erg/cc]
const double Ms_SI = Ms_CGS*1e3; //Saturation magnetisation: [A/m]
const double K_SI = K_CGS*1e-1; //: Magnetocrystlline first-order anis. constant: [J/m^3]
const double volume = a*a*a; // Macrospin volume: [m^3]
const double lambda = 0.1; // Microscopic coupling constant: adimensional


//---Simulation paramters
const double T = 0.0; // Magnetic moment temperature (electron temperature in this model): [K]
const double B_app = 0.5; // External field amplitude: [T]
const double bx = 0.8; // H_ext_x/H_ext 
const double by = 0.6; // H_ext_y/H_ext
const double bz = 0.0; // H_ext_z/H_ext
const double ex = 0.0; // H_ani_x
const double ey = 0.0; // H_ani_y
const double ez = 1.0; // H_ani_z
const double alpha_par = (2.0/3.0)*(T/Tc)*lambda; //Longitudinal damping parameter: adimensional. Avail. only for T<Tc
const double alpha_perp = lambda*(1-(T/(3*Tc))); //Transversal damping parameter: adimensional. Avail. only for T<Tc
const int t_min=0; // Time will be given as an integer. It needs to be multiplied with 10^-12 at the end.
const int t_max=3000;
const int delta_t=1;

//---Initial conditions
const double mx_0 = 1.0;
const double my_0 = 0.0;
const double mz_0 = 0.0;


}

#endif
//---End of input.h file.