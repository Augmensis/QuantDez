#pragma once
#include "stdafx.h"
#ifndef __STATS_ENGINE_H__
#define __STATS_ENGINE_H__
#define _USE_MATH_DEFINES

class StatsEngine {

public:
	double N_CDF(const double& data);
	double N_PDF(const double& data);
};

#endif __STATS_ENGINE_H__