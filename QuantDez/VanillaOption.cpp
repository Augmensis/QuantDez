#pragma once
#include "stdafx.h"
#ifndef __VANILLA_OPTION_CPP__
#define __VANILLA_OPTION_CPP__

#include "VanillaOption.h"
#include <cmath>

// Initialises instance
void VanillaOption::init() {
	K = 100.0;	
	r = 0.05;	// %5 interest rate
	T = 1.0;	// One year until maturity
	S = 100.0;	// Option is "At The Money" as Spot == Strike
	sigma = 2;	// 20% Volatility 
}

// Copies member data
void VanillaOption::copy(const VanillaOption& rhs){
	K = rhs.getK();
	r = rhs.getr();
	T = rhs.getT();
	S = rhs.getS();
	sigma = rhs.getsigma();
}

VanillaOption::VanillaOption() { init(); }

VanillaOption::VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma){
	K = _K;
	r = _r;
	T = _T;
	S = _S;
	sigma = _sigma;
}

#endif __VANILLA_OPTION_CPP__