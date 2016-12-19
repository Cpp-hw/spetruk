#include "Prism.h"



void Prism::createRegular()
{
	std::cout << "Enter prism sides: ";
	std::cin >> n;

	std::cout << "\nEnter prism R: ";
	std::cin >> r;
	
	std::cout << "\nEnter prism height: ";
	std::cin >> h;


	a = 2 * r*sin(M_PI / n);
	sBase = n / 2. * r*r*sin(2 * M_PI / n);
	v = sBase*h;
}

void Prism::createNonRegular()
{
	std::vector<Point2d> points;
	std::cout << "Enter prism sides: ";
	std::cin >> n;

	std::cout << "\nEnter prism height: ";
	std::cin >> h;

	for (unsigned int i = 0; i < n; i++)
	{
		Point2d tmp;
		std::cout << "Enter X" << i + 1 << ": ";
		std::cin >> tmp.x;

		std::cout << "Enter Y" << i + 1 << ": ";
		std::cin >> tmp.y;

		points.push_back(tmp);
	}
	int length = points.size()-1;
	sBase = 0;
	for (unsigned int i = 0; i < length; i++)
	{
		sBase += (points[i].x*points[i + 1].y - points[i].y*points[i+1].x);
	}
	sBase += points[length].x*points[0].y - points[length].y*points[0].x;

	sBase = abs(sBase/2.);
	v = sBase*h;
	a = sqrt(pow((points[length].x - points[0].x), 2) + pow((points[length].y - points[0].y), 2));
}

Prism::Prism()
{
	int input;
	
	while (true)
	{
		std::cout << "Is prism Regular?\n1) yes\n2) no\nInput: ";
		std::cin >> input;
		if (input == 1)
		{
			createRegular();
			break;
		}
		if (input == 2)
		{
			createNonRegular();
			break;
		}
	}

	displayInfo();
}

void Prism::displayInfo()
{
	std::cout << "Prism info\n\n";
	std::cout << "Prism Borders: "       << n + 2 << std::endl;
	std::cout << "Prism Base Area: "     << sBase << std::endl;
	std::cout << "Prism border length: " << a     << std::endl;
	std::cout << "Prism volume: "        << v     << std::endl;
	std::cout << "Prism height: "        << h     << std::endl;
}


Prism::~Prism()
{
}
