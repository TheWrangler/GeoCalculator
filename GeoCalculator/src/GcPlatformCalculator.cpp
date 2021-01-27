#include "stdafx.h"
#include "../include/GcPlatformCalculator.h"
#include "../include/GcTransformMatrix.h"
#include "../include/GcTransformMatrixFactory.h"

using namespace GeoCalculator;

GcPlatformCalculator::GcPlatformCalculator(bool rad)
	: GcGeoCalculator(rad)
{
	_attiVertex = GcVertex(0.0, 0.0, 0.0);
	update();
}

GcPlatformCalculator::GcPlatformCalculator(const GcVertex& src, const GcVertex& dst, const GcVertex& atti, bool rad)
	: GcGeoCalculator(src, dst, rad)
{
	_attiVertex = atti;
	update();
}

GcPlatformCalculator::~GcPlatformCalculator()
{
}

void GcPlatformCalculator::update()
{

}

void GcPlatformCalculator::setAttiVertex(const GcVertex& vertex, bool rad)
{

}

GcVertex GcPlatformCalculator::dstCoorInSrc() const
{
	return GcVertex();
}

double GcPlatformCalculator::azi() const
{
	return 0.0;
}

double GcPlatformCalculator::ele() const
{
	return 0.0;
}
