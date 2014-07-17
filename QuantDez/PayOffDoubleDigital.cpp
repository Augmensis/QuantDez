#pragma once
#include "stdafx.h"
#ifndef __PAY_OFF_DOUBLE_DIGITAL_CPP__
#define __PAY_OFF_DOUBLE_DIGITAL_CPP__

// Constructor with single Price strike
PayOffDoubleDigital::PayOffDoubleDigital(const double _U, const double _D) { 
	U = _U;
	D = _D;
}

PayOffDoubleDigital::~PayOffDoubleDigital(){}

// Standard European Call Payoff
double PayOffDoubleDigital::operator() (const double S) const {
	if (S >= D && S <= U) {
		return 1.0;
	}
	else {
		return 0.0;
	}
}

#endif __PAY_OFF_DOUBLE_DIGITAL_CPP__