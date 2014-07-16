#pragma once
#include "stdafx.h"
#ifndef __STATS_ENGINE_CPP__
#define __STATS_ENGINE_CPP__

// Standard normal probability density function
double StatsEngine::N_PDF(const double& data) {
	return (1.0 / (pow(2 * M_PI, 0.5)))*exp(-0.5 * data * data);
}

// An approximation to the cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double StatsEngine::N_CDF(const double& data) {
	double k = 1.0 / (1.0 + 0.2316419 * data);
	double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

	if (data >= 0.0) {
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * data * data) * k_sum);
	}
	else {
		return 1.0 - N_CDF(-data);
	}
}

#endif __STATS_ENGINE_CPP__