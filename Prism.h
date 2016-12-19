#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <conio.h>
#include <vector>




class Prism
{
private:
	unsigned int n;
	double sBase, v;
	double h;
	double a;
	double r;
	struct Point2d
	{
		double x;
		double y;
	};
	void createRegular();
	void createNonRegular();
public:
	Prism();
	void displayInfo();
	~Prism();
};

