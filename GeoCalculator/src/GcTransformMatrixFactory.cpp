#include "stdafx.h"
#include "../include/GcTransformMatrixFactory.h"
#include "../include/GcConstVariable.h"
#include "math.h"

using namespace GeoCalculator;

GcTransformMatrixFactory::GcTransformMatrixFactory()
{
}


GcTransformMatrixFactory::~GcTransformMatrixFactory()
{
}

GcTransformMatrix GcTransformMatrixFactory::createSpherial2Earth(double lon, double lat, double hei, bool rad)
{
	if (!rad)
	{
		lon = GcConstVariable::angle2rad(lon);
		lat = GcConstVariable::angle2rad(lat);
	}

	GcVertex vertex1(cos(lat)*cos(lon), cos(lat)*cos(lon), 0);
	GcVertex vertex2(cos(lat)*sin(lon), cos(lat)*sin(lon), 0);
	GcVertex vertex3(0, sin(lat), sin(lat));

	return GcTransformMatrix(vertex1, vertex2, vertex3);
}

GcTransformMatrix GcTransformMatrixFactory::createSpherial2Earth(const GcVertex& gcVertex, bool rad)
{
	double lon, lat, hei;

	lon = gcVertex.x();
	lat = gcVertex.y();
	hei = gcVertex.z();

	return createSpherial2Earth(lon, lat, hei, rad);
}

GcTransformMatrix GcTransformMatrixFactory::createEarth2Geo(double lon, double lat, bool rad)
{
	if (!rad)
	{
		lon = GcConstVariable::angle2rad(lon);
		lat = GcConstVariable::angle2rad(lat);
	}

	GcVertex vertex1(-sin(lon), cos(lon), 0);
	GcVertex vertex2(-sin(lat)*cos(lon), -sin(lat)*sin(lon), cos(lat));
	GcVertex vertex3(cos(lat)*cos(lon), cos(lat)*sin(lon), sin(lat));

	return GcTransformMatrix(vertex1, vertex2, vertex3);
}

GcTransformMatrix GcTransformMatrixFactory::createEarth2Geo(const GcVertex& gcVertex, bool rad)
{
	double lon, lat;

	lon = gcVertex.x();
	lat = gcVertex.y();

	return createEarth2Geo(lon, lat, rad);
}

GcTransformMatrix GcTransformMatrixFactory::createGeo2Platform(double lon, double lat, double yaw, double pitch, double roll, bool rad)
{
	return GcTransformMatrix();
}

GcTransformMatrix GcTransformMatrixFactory::createGeo2Platform(const GcVertex& gcPosVertex, const GcVertex& gcAttiVertex, bool rad)
{
	return GcTransformMatrix();
}