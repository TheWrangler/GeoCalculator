#include "stdafx.h"
#include "../include/GcTransformMatrix.h"
#include "../include/GcConstVariable.h"
#include "math.h"

using namespace GeoCalculator;

GcTransformMatrix::GcTransformMatrix()
{
	_gcVertex[0] = GcVertex(1, 0, 0);
	_gcVertex[1] = GcVertex(0, 1, 0);
	_gcVertex[2] = GcVertex(0, 0, 1);
}

GcTransformMatrix::GcTransformMatrix(const GcVertex& r1, const GcVertex& r2, const GcVertex& r3)
{
	_gcVertex[0] = r1;
	_gcVertex[1] = r2;
	_gcVertex[2] = r3;
}

GcTransformMatrix::GcTransformMatrix(double r1c1, double r1c2, double r1c3, double r2c1, double r2c2, double r2c3, double r3c1, double r3c2, double r3c3)
{
	_gcVertex[0].setXYZ(r1c1, r1c2, r1c3);
	_gcVertex[1].setXYZ(r2c1, r2c2, r2c3);
	_gcVertex[2].setXYZ(r3c1, r3c2, r3c3);
}

GcTransformMatrix::~GcTransformMatrix()
{
}

GcTransformMatrix GcTransformMatrix::transpose() const
{
	GcTransformMatrix transformMatrix;
	transformMatrix.setRow(0, _gcVertex[0].x(), _gcVertex[1].x(), _gcVertex[2].x());
	transformMatrix.setRow(1, _gcVertex[0].y(), _gcVertex[1].y(), _gcVertex[2].y());
	transformMatrix.setRow(2, _gcVertex[0].z(), _gcVertex[1].z(), _gcVertex[2].z());
	return transformMatrix;
}

GcVertex GcTransformMatrix::operator*(const GcVertex& vertex) const
{
	GcVertex gcVertex;
	gcVertex.setX(_gcVertex[0] * vertex);
	gcVertex.setY(_gcVertex[1] * vertex);
	gcVertex.setZ(_gcVertex[2] * vertex);
	return gcVertex;
}

GcTransformMatrix GcTransformMatrix::operator*(const GcTransformMatrix& gcTransformMatrix) const
{
	GcTransformMatrix transposeMatrix = gcTransformMatrix.transpose();
	GcTransformMatrix resMatrix;

	resMatrix.setRow(0, this->row(0)*transposeMatrix.row(0), this->row(0)*transposeMatrix.row(1), this->row(0)*transposeMatrix.row(2));
	resMatrix.setRow(1, this->row(1)*transposeMatrix.row(0), this->row(1)*transposeMatrix.row(1), this->row(1)*transposeMatrix.row(2));
	resMatrix.setRow(2, this->row(2)*transposeMatrix.row(0), this->row(2)*transposeMatrix.row(1), this->row(2)*transposeMatrix.row(2));
	return resMatrix;
}

GcVertex GcTransformMatrix::transform(const GcVertex& vertex) const
{
	return operator*(vertex);
}