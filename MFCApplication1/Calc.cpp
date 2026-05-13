#include "pch.h"
#include "Calc.h"
#define _USE_MATH_DEFINES 
#include <cmath>


CCalc::CCalc()
{
}


CCalc::~CCalc()
{
}


dPoint_s CCalc::GetXY(Args_s args, Par_s Par)
{
	dPoint_s xy;
	// 
	xy.x = args.t; //sin(t)
	xy.y = sin(args.t + Par.a);
	return xy;
}

void CCalc::CalcArgStep(int win_width)
{
	m_dX = (M_PI * 2. / (win_width)) * 2; // 2 точки по Х шаг
}

void CCalc::GetArgRange(double& min_arg, double& max_arg)
{
	min_arg = 0;
	max_arg = 2. * M_PI;
}
