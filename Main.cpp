#include "Prism.h"

int main() 
{
	int input;
	Prism* prism = nullptr;

	do
	{
		system("clear");
		std::cout << "Enter:\n1) To create prism;\n2) To display prism info;\n3) To exit program.\nInput: ";
		std::cin >> input;
		if (input == 1)
		{
			if (prism != nullptr)
			{ 
				delete prism;
				prism = nullptr;
			}
			prism = new Prism();
			getch();
		}
		if (input == 2)
		{
			if (prism != nullptr)
				prism->displayInfo();
			else
			{
				std::cout << "You have not created prism";
			}
			getch();
		}



	} while (input!=3);
	

	return 0;
}