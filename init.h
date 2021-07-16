//---This is the init.h file.
#pragma once

#ifndef INIT_H
#define INIT_H

//---Standard libraries


//---User-defined libraries
#include"tempscaling.h"

//---Namespace init

namespace init{
	
//---Variables


//---Functions
int parameters();
int files();
int sim();

}

namespace init{


	namespace internal{
		int run();
	}
}


#endif
//---End of init.h file.