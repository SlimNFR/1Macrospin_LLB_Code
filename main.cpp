//---This is the main.cpp file. It calls the main routines of the code.


//---Standard libraries
#include<iostream>

//---User-defined libraries
#include"input.h"
#include"solver.h"
#include"dynamics.h"
#include"particle.h"
#include"field.h"
#include"init.h"
#include"tempscaling.h"
#include"interpolate.h"
#include"output.h"

int main()
{

//Left to do:


//Assumptions:
//T=0;
//I'll do it without the longitudinal field initially.
//No shape anis.
//constant chi_par
//constant K, Ms


particle::mx = input::mx_0;
particle::my = input::my_0;
particle::mz = input::mz_0;

//field::calculate();
/*
field::uniax_anis_f(particle::mx, particle::my, particle::mz,
					input::ex, input::ey, input::ez,
					input::K_SI, input::Ms_SI, 
					field::Bx_ani, field::By_ani, field::Bz_ani);

field::zeeman_f(input::B_app, input::bx, input::by, input::bz,
				field::Bx_app, field::By_app, field::Bz_app);

field::effective_f(field::Bx_ani, field::By_ani, field::Bz_ani,
				   field::Bx_app, field::By_app, field::Bz_app,
				   field::Bx_eff, field::By_eff, field::Bz_eff);
*/


//std::cout<<"x_eff: "<<field::Bx_eff<<"|y_eff: "<<field::By_eff<<"|z_eff: "<<field::Bz_eff<<"|x_ani: "<<field::Bx_ani<<"|y_ani: "<<field::By_ani<<"|z_ani: "<<field::Bz_ani<<"\n";

/*
solver::heun_scheme(&dynamics::LLB_equation,
					input::mx_0, input::my_0, input::mz_0,
					input::gamma, input::alpha_par, input::alpha_perp,
					input::t_min, input::t_max, input::delta_t, 
					field::Bx_eff, field::By_eff, field::Bz_eff,
					solver::sim_time, particle::mx,particle::my,particle::mz);
*/

init::internal::run();
double temp_me;
double temp_T=355.5;
tempscaling::equilibrium_magn_f(temp_T, cubicspline::x_interpol, cubicspline::y_interpol, cubicspline::b, cubicspline::c, cubicspline::d, temp_me);
std::cout<<"T: "<<temp_T<<"| me:"<<temp_me<<"\n";

output::close_files();

return 0;
}





//---End of main.cpp file
