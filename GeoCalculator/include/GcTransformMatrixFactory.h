#pragma once
#include "GcTransformMatrix.h"

namespace GeoCalculator
{
	class __declspec(dllexport) GcTransformMatrixFactory
	{
	public:
		GcTransformMatrixFactory();
		~GcTransformMatrixFactory();

	public:
		/*
		* ���ɵ���γ����ϵ������ֱ������ϵ��ת������
		*
		* x:ָ��0�Ⱦ��ߣ����������棩
		* z:ָ�򱱼�
		* y:��xoz������������ϵ
		*
		*/
		static GcTransformMatrix createSpherial2Earth(double lon, double lat, double hei, bool rad = false);
		static GcTransformMatrix createSpherial2Earth(const GcVertex& gcVertex, bool rad = false);

		/*
		* ���ɵ���ֱ������ϵ����������ϵ��ת������
		*
		* x:ָ�򵱵صĵ�����
		* y:ָ�򵱵صĵ�����
		* z:ָ�򵱵صĵ�������
		*
		*/
		static GcTransformMatrix createEarth2Geo(double lon, double lat, bool rad = false);
		static GcTransformMatrix createEarth2Geo(const GcVertex& gcVertex, bool rad = false);

		/*
		* ���ɵ�������ϵ����������ϵ��ת������
		*/
		static GcTransformMatrix createGeo2Platform(double lon, double lat, double yaw, double pitch, double roll, bool rad = false);
		static GcTransformMatrix createGeo2Platform(const GcVertex& gcPosVertex, const GcVertex& gcAttiVertex, bool rad = false);
	};
}

