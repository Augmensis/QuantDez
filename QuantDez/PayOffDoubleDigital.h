#pragma once
#include "stdafx.h"
#ifndef __PAY_OFF_DOUBLE_DIGITAL_H__
#define __PAY_OFF_DOUBLE_DIGITAL_H__

class PayOffDoubleDigital : public PayOff {

private:
	double U;	// Upper Strike Price
	double D;	// Lower Strike Price

public:
	PayOffDoubleDigital(const double _U, const double _D);
	virtual ~PayOffDoubleDigital();

	// Virtual function override
	virtual double operator() (const double S) const;	// Max PayOff is max(S-K,0)

};

#endif __PAY_OFF_DOUBLE_DIGITAL_H__