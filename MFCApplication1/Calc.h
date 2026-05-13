#pragma once
struct dPoint_s
{
	double x = 0;
	double y = 0;
	dPoint_s() {};//default
	dPoint_s(double x1, double y1) :x(x1), y(y1) {}
};

struct Par_s
{
	double a = 0;
	double b = 0;
	Par_s() {};//default
	Par_s(double a1, double b1) :a(a1), b(b1) {}
};

struct Args_s
{
	double t;
	Args_s() {}; //default
	Args_s(double t1) :t(t1) {};
	//....
};

class CCalc
{
public:
	CCalc();
	~CCalc();
	dPoint_s GetXY(Args_s args, Par_s par);
	void CalcArgStep(int win_width);
	void GetArgRange(double& min_arg, double& max_arg);
protected:
	double m_dX = 1;
};
