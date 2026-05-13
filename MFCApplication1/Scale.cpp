#include "pch.h"
#include "Scale.h"
#define _USE_MATH_DEFINES
#include "math.h"

CScale::CScale()
	: m_Scale(0.)
	, m_CenterPoint(0, 0)
{
}


CScale::~CScale()
{
}


void CScale::SetWinPar(int Xwidth, int YHeight)
{
	double scX, scY;
	scY = ((double)YHeight - 2. * BORDER_W) / 2.;
	scX = ((double)Xwidth - 2. * BORDER_W) / (2. * M_PI);
	m_Scale = min(scX, scY);
	m_CenterPoint.x = BORDER_W;
	m_CenterPoint.y = (YHeight) / 2;

}


CPoint CScale::GetPoint(Args_s args, Par_s par)
{
	CPoint res;
	dPoint_s dp = GetXY(args, par);
	res.x = floor(m_Scale * dp.x + .49999);
	res.y = -floor(m_Scale * dp.y + .49999);
	res += m_CenterPoint;
	return res;
}

size_t CScale::GetPoints(std::vector<CPoint>& points_array, Par_s par)
{
	points_array.clear(); //стираем старые

	// расчитаем шаг 
	double dX = m_dX, min_X, max_X;
	GetArgRange(min_X, max_X);
	for (double X = min_X; X < max_X; X += dX)
	{
		CPoint pt = GetPoint(Args_s(X), par);
		points_array.push_back(pt);
	}
	return points_array.size();
}