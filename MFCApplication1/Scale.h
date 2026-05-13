#pragma once
#include "Calc.h"
#include "atltypes.h"
#include <vector>
#define BORDER_W 10

class CScale :
	public CCalc
{
public:
	CScale();
	~CScale();
protected:
	double m_Scale; // масштабный коэффициент
	CPoint m_CenterPoint; // смещение - перенос начала координат из лев верх угла
public:
	void SetWinPar(int Xwidth, int YHeight);
	CPoint GetPoint(Args_s args, Par_s Par);
	size_t GetPoints(std::vector<CPoint>& points_array, Par_s par);
};
