#pragma once
#include "stdafx.h"
#ifndef __PAY_OFF_CALL_CPP__
#define __PAY_OFF_CALL_CPP__

// Constructor with single Price strike
PayOffCall::PayOffCall(const double _K) { K = _K; }

PayOffCall::~PayOffCall(){}

// Standard European Call Payoff
double PayOffCall::operator() (const double S) const {
	return std::max(S - K, 0.0);
}

#endif __PAY_OFF_CALL_CPP__