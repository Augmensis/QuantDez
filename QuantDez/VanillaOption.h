#pragma once
#include "stdafx.h"
#ifndef __VANILLA_OPTION_H__
#define __VANILLA_OPTION_H__


class VanillaOption {

private:
	void init();
	void copy(const VanillaOption& rhs);

	double K;		// Strike Price
	double r;		// Risk-Free Rate
	double T;		// Maturity Time
	double S;		// Underlying Asset Price
	double sigma;	// Volatility of underlying asset

public:
	VanillaOption();	// Default Constructor

	VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma);	// Params Constructor

	VanillaOption(const VanillaOption& rhs);	// Copy Constructor

	VanillaOption& operator = (const VanillaOption& rhs);	// Assignment Operator

	virtual ~VanillaOption();	// Destructor


	// Selector "Getter" Methods for option params
	double getK() const;
	double getr() const;
	double getT() const;
	double getS() const;
	double getsigma() const;


	// Option Price calculation methods
	double calcCallPrice() const;
	double calcPutPrice() const;

};

#endif __VANILLA_OPTION_H__