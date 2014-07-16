#pragma once
#include "stdafx.h"
#ifndef __VANILLA_OPTION_CPP__
#define __VANILLA_OPTION_CPP__

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

// Copy constructor
VanillaOption::VanillaOption(const VanillaOption& rhs){
	copy(rhs);
}

// Assignment Operator
VanillaOption& VanillaOption::operator=(const VanillaOption& rhs) {
	if (this == &rhs) return *this;
	copy(rhs);
	return *this;
}

// Destructor
VanillaOption::~VanillaOption() {}

StatsEngine s;

double VanillaOption::getK() const { return K; }
double VanillaOption::getr() const { return r; }
double VanillaOption::getT() const { return T; }
double VanillaOption::getS() const { return S; }
double VanillaOption::getsigma() const { return sigma; }

double VanillaOption::calcCallPrice() const {
	double sigmaSqrtT = sigma * sqrt(T);
	double delta1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigmaSqrtT;
	double delta2 = delta1 - sigmaSqrtT;

	return S * s.N_CDF(delta1) - K * exp(-r * T) * s.N_CDF(delta2);
}

double VanillaOption::calcPutPrice() const {
	double sigmaSqrtT = sigma * sqrt(T);
	double delta1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigmaSqrtT;
	double delta2 = delta1 - sigmaSqrtT;

	return K * exp(-r * T) * s.N_CDF(-delta2) - S * s.N_CDF(-delta1);
}


#endif __VANILLA_OPTION_CPP__