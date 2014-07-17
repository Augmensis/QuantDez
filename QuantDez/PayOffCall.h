#pragma once
#include "stdafx.h"
#ifndef __PAY_OFF_CALL_H__
#define __PAY_OFF_CALL_H__

class PayOffCall : public PayOff {

private:
	double K;	// Strike Price

public:
	PayOffCall(const double _K);
	virtual ~PayOffCall();

	// Virtual function override
	virtual double operator() (const double S) const;	// Max PayOff is max(S-K,0)

};

#endif __PAY_OFF_CALL_H__