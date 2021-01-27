#include "stdafx.h"
#include "../include/GcGeoCalculator.h"
#include "../include/GcTransformMatrix.h"
#include "../include/GcTransformMatrixFactory.h"
#include "../include/GcConstVariable.h"
#include "math.h"

using namespace GeoCalculator;

GcGeoCalculator::GcGeoCalculator(bool rad)
{
	_srcVertex = GcVertex(0, 0, 0);
	_dstVertex = GcVertex(0, 0, 0);
	_rad = rad;

	update();
}

GcGeoCalculator::GcGeoCalculator(const GcVertex& src, const GcVertex& dst, bool rad)
{
	_srcVertex = src;
	_dstVertex = dst;
	_rad = rad;

	update();
}

GcGeoCalculator::GcGeoCalculator(double srcLon, double srcLat, double srcHei, double dstLon, double dstLat, double dstHei, bool rad)
{
	_srcVertex = GcVertex(srcLon, srcLat, srcHei);
	_dstVertex = GcVertex(dstLon, dstLat, dstHei);
	_rad = rad;

	update();
}

GcGeoCalculator::~GcGeoCalculator()
{
}

void GcGeoCalculator::setSrcVertex(const GcVertex& vertex, bool rad)
{ 
	if (_rad != rad)
	{
		if (_rad)
		{
			_srcVertex.setX(GcConstVariable::angle2rad(vertex.x()));
			_srcVertex.setY(GcConstVariable::angle2rad(vertex.y()));
		}
		else
		{
			_srcVertex.setX(GcConstVariable::rad2angle(vertex.x()));
			_srcVertex.setY(GcConstVariable::rad2angle(vertex.y()));
		}
	}
	else _srcVertex = vertex;
 
	update(); 
}

void GcGeoCalculator::setDstVertex(const GcVertex& vertex, bool rad)
{ 
	if (_rad != rad)
	{
		if (_rad)
		{
			_dstVertex.setX(GcConstVariable::angle2rad(vertex.x()));
			_dstVertex.setY(GcConstVariable::angle2rad(vertex.y()));
		}
		else
		{
			_dstVertex.setX(GcConstVariable::rad2angle(vertex.x()));
			_dstVertex.setY(GcConstVariable::rad2angle(vertex.y()));
		}
	}
	else _dstVertex = vertex;

	update(); 
}

void GcGeoCalculator::update()
{
	_dstCoorInSrc = dstCoorInSrc();
}

GcVertex GcGeoCalculator::srcCoorInEarth() const
{
	GcTransformMatrix gcTransformMatrix = GcTransformMatrixFactory::createSpherial2Earth(_srcVertex, _rad);
	double n = GcConstVariable::n(_srcVertex.y(), _rad);
	GcVertex vertex(n, _srcVertex.z(), n*(1 - GcConstVariable::e2));
	return gcTransformMatrix.transform(vertex);
}

GcVertex GcGeoCalculator::dstCoorInEarth() const
{
	GcTransformMatrix gcTransformMatrix = GcTransformMatrixFactory::createSpherial2Earth(_dstVertex, _rad);
	double n = GcConstVariable::n(_dstVertex.y(), _rad);
	GcVertex vertex(n, _dstVertex.z(), n*(1 - GcConstVariable::e2));
	return gcTransformMatrix.transform(vertex);
}

GcVertex GcGeoCalculator::dstCoorInSrc() const
{
	GcVertex gcSrcCoor = srcCoorInEarth();
	GcVertex gcDstCoor = dstCoorInEarth();
	GcTransformMatrix gcTransformMatrix = GcTransformMatrixFactory::createEarth2Geo(_srcVertex, _rad);
	return gcTransformMatrix.transform(gcDstCoor - gcSrcCoor);
}

double GcGeoCalculator::azi() const
{
	double azi = GcConstVariable::rad2angle(atan2(_dstCoorInSrc.x(),_dstCoorInSrc.y()));
	if (azi < 0)
		azi += 360;

	return azi;
}

double GcGeoCalculator::ele() const
{
	double r = sqrt(_dstCoorInSrc.x() * _dstCoorInSrc.x() + _dstCoorInSrc.y() * _dstCoorInSrc.y());
	double ele = GcConstVariable::rad2angle(atan2(_dstCoorInSrc.z(), r));
	return ele;
}

double GcGeoCalculator::distance() const
{
	return _dstCoorInSrc.norm();
}
