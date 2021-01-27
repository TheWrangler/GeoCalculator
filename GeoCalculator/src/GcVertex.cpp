#include "stdafx.h"
#include "../include/GcVertex.h"
#include "math.h"

using namespace GeoCalculator;

GcVertex::GcVertex()
{
	_x = 0.0;
	_y = 0.0;
	_z = 0.0;
	_m = 0.0;
}

GcVertex::GcVertex(double x, double y, double z, double m)
{
	_x = x;
	_y = y;
	_z = z;
	_m = m;
}


GcVertex::~GcVertex()
{
}

GcVertex GcVertex::operator+(const GcVertex& vertex) const
{
	GcVertex gcVertex;
	gcVertex._x = this->_x + vertex._x;
	gcVertex._y = this->_y + vertex._y;
	gcVertex._z = this->_z + vertex._z;
	return gcVertex;
}

GcVertex GcVertex::operator-(const GcVertex& vertex) const
{
	GcVertex gcVertex;
	gcVertex._x = this->_x - vertex._x;
	gcVertex._y = this->_y - vertex._y;
	gcVertex._z = this->_z - vertex._z; 
	return gcVertex;
}

double GcVertex::operator*(const GcVertex& vertex) const
{
	return this->_x * vertex._x + this->_y * vertex._y + this->_z * vertex._z;
}

double GcVertex::norm() const
{
	return sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z);
}

double GcVertex::dist(const GcVertex& vertex) const
{
	GcVertex gcVertex = this->operator-(vertex);
	return gcVertex.norm();
}