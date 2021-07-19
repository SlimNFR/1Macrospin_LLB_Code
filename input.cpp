//---This is the input.cpp file. It defines the input.h functions.


//---Standard libraries
#include<cmath>

//---User-defined libraries
#include"input.h"

//---Namespace input

namespace input{
	
// //---Global constants
// const double mu0=4.0*M_PI*1e-7; //Vacuum permeability: [H/m]
// const double gamma = 1.76*1e11; // Gyromagnetic ratio: [rad/(s*T)]
// const double k_B = 1.381*1e-23; // Boltzmann constant [J/K]


// //---Material parameters (Ni)
// const int n_at = 1.0; //Number of atoms per unit cell: adim.
// const double a = 0.35*1e-9; // Lattice spacing: [m]
// const double Tc = 631.0; // Curie temperature: [K]
// const double Ms0_CGS = 500.0; // Saturation magnetisation: [emu/cc]
// const double K0_CGS = 5.3*1e4; // Magnetocrystlline first-order anis. constant: [erg/cc]
// const double Ms0_SI = Ms0_CGS*1e3; //Saturation magnetisation: [A/m]
// const double K0_SI = K0_CGS*1e-1; //: Magnetocrystlline first-order anis. constant: [J/m^3]
double m_e; //Equilibrium magnetisation: []
double Ms_T; //Saturation magnetisation at T
double K_T;// Magnetocrystalline anisotropy constant at T
// const double volume = a*a*a; // Macrospin volume: [m^3]
// const double mu_s = Ms_SI*volume/n_at; // Atomic magnetic moment: [J/T]
// const double lambda = 0.1; // Microscopic coupling constant: adimensional
double chi_par; //Parallel susceptibility: []
double chi_perp; //Perpendicular susceptibility: []
// const double eps = 1.0; //SW correction factor: adim.

// //---Simulation paramters
double T=300.0; // Magnetic moment temperature (electron temperature in this model): [K]
double B_app=1.0; // External field amplitude: [T]
double B_theta=30.0*M_PI/180.0;//angle with respect to EA
double B_phi=0.0*M_PI/180.0; //Angle between in-plane field projection and the Ox axis
double bx = sin(B_theta)*cos(B_phi); // H_ext_x/H_ext 
double by = sin(B_theta)*sin(B_phi); // H_ext_y/H_ext
double bz = cos(B_theta); // H_ext_z/H_ext
// const double ex = 0.0; // H_ani_x
// const double ey = 0.0; // H_ani_y
// const double ez = 1.0; // H_ani_z
double alpha_par; //Longitudinal damping parameter: adimensional. Avail. only for T<Tc
double alpha_perp; //Transversal damping parameter: adimensional. Avail. only for T<Tc
// const int t_min=0; // Time will be given as an integer. It needs to be multiplied with 10^-12 at the end.
// const int t_max=3000;
// const int delta_t=1;

// //---Initial conditions
// const double mx_0 = 1.0;
// const double my_0 = 0.0;
// const double mz_0 = 0.0;

// //---Simulation



// const bool m_vs_T_curve = true;
// const bool chipar_vs_T_curve = true;
// const bool K_vs_T_curve = true;




}


//---End of input.cpp file.

