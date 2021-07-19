//---This is the main.cpp file. It calls the main routines of the code.


//---Standard libraries
#include<iostream>

//---User-defined libraries
#include"input.h"
#include"solver.h"
#include"particle.h"
#include"field.h"
#include"init.h"
#include"tempscaling.h"
#include"interpolate.h"
#include"output.h"
#include"simulation.h"

int main()
{


init::internal::run();
//std::cout<<"T: "<<input::T<<"| B_app: "<<input::B_app<<" "<<"\n";
output::close_files();
return 0;
}





//---End of main.cpp file
