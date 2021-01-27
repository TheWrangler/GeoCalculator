#include "stdafx.h"
#include "../include/GcConstVariable.h"
#include "math.h"

using namespace GeoCalculator;

const double GcConstVariable::pi = 3.1415926;
const double GcConstVariable::a = 6378.137;
const double GcConstVariable::e2 = 0.00669437999013;

GcConstVariable::GcConstVariable()
{
}


GcConstVariable::~GcConstVariable()
{
}

double GcConstVariable::angle2rad(double angle)
{
	return angle / 180.0 * pi;
}

double GcConstVariable::rad2angle(double rad)
{
	return rad * 180.0 / pi;
}

double GcConstVariable::n(double lat, bool rad)
{
	if (!rad)
		lat = angle2rad(lat);

	return a / sqrt(1 - e2*sin(lat)*sin(lat));
}
