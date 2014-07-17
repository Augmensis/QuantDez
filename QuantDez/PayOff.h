#pragma once
#include "stdafx.h"
#ifndef __PAY_OFF_H__
#define __PAY_OFF_H__

class PayOff {

public:
	PayOff(){};
	virtual ~PayOff(){};

	// Abstract Function Object
	// Pure virtual method
	virtual double operator() (const double S) const = 0;
};

#endif __PAY_OFF_H__