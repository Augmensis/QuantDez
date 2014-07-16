#ifndef __VANILLA_OPTION_CPP__
#define __VANILLA_OPTION_CPP__

#include "VanillaOption.h"
#include <cmath>

void VanillaOption::init() {
	K = 100.0;	
	r = 0.05;	// %5 interest rate
	T = 1.0;	// One year until maturity
	S = 100.0;	// Option is "At The Money" as Spot == Strike
	sigma = 2;	// 20% Volatility 
}


#endif //__VANILLA_OPTION_CPP__