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
const double k_B = 1.381*1e-23; // Boltzmann constant [J/K]


//---Material parameters (Ni)
const int n_at = 1.0; //Number of atoms per unit cell: adim.
const double a = 0.35*1e-9; // Lattice spacing: [m]
const double Tc = 631.0; // Curie temperature: [K]
const double Ms0_CGS = 500.0; // Saturation magnetisation: [emu/cc]
const double K0_CGS = 5.3*1e4; // Magnetocrystlline first-order anis. constant: [erg/cc]
const double Ms0_SI = Ms0_CGS*1e3; //Saturation magnetisation: [A/m]
const double K0_SI = K0_CGS*1e-1; //: Magnetocrystlline first-order anis. constant: [J/m^3]
extern double m_e; //Equilibrium magnetisation: []
extern double Ms_T; //Saturation magnetisation at T
extern double K_T; //Magnetocrystalline anisotropy constant at T
const double volume = a*a*a; // Macrospin volume: [m^3]
const double mu_s = Ms0_SI*volume/n_at; // Atomic magnetic moment: [J/T]
const double lambda = 0.1; // Microscopic coupling constant: adimensional
extern double chi_par; //Parallel susceptibility: []
extern double chi_perp; //Perpendicular susceptibility: []
const double eps = 1.0; //SW correction factor: adim.

//---Simulation paramters
extern double T; // Magnetic moment temperature (electron temperature in this model): [K]
extern double B_app; // External field amplitude: [T]
extern double B_theta;//angle with respect to EA
extern double B_phi; //Angle between in-plane field projection and the Ox axis
extern double bx;// H_ext_x/H_ext 
extern double by; // H_ext_y/H_ext
extern double bz; // H_ext_z/H_ext
const double ex = 0.0; // H_ani_x
const double ey = 0.0; // H_ani_y
const double ez = 1.0; // H_ani_z
extern double alpha_par; //Longitudinal damping parameter: adimensional. Avail. only for T<Tc
extern double alpha_perp; //Transversal damping parameter: adimensional. Avail. only for T<Tc

const int t_min_equil=0; // Time will be given as an integer. It needs to be multiplied with 10^-12 at the end.
const int t_max_equil=400000;
const int delta_t_equil=10;
const double timescale_equil=1e-15;
const double TOL_EQ = 1e-4;//Tolerance for stopping condition using the torque modulus.


const int t_min_laser_dynamics=0;
const int t_max_laser_dynamics=400000;
const int delta_t_laser_dynamics=10;
const double timescale_laser_dynamics = 1e-15;
const double TOL_LD = 1e-4;


const int pulse_duration = 10000; //fs !!Important, this needs to be in the same time unit as the timescale_laser_dynamics
const double T_pulse  = 600.0;

//---Initial conditions
const double mx_0 = 1.0;
const double my_0 = 0.0;
const double mz_0 = 0.0;

//---Simulation

const bool m_vs_T_curve = false;
const bool chipar_vs_T_curve = false;
const bool K_vs_T_curve = false;
const bool equilibrate = true;
const bool laser_dynamics = true;


}

#endif
//---End of input.h file.
