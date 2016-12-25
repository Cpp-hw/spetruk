#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

void task1()
{
	int a = 3;
	int b = 11;

	cout << a << " " << b << endl;
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	cout << a << " " << b << endl;
}

void task2(int n)
{
	// p = i=1..n P (1+(1/sqrt^4(i)))
	double p = 1;

	for(int i = 1; i < n; i++)
	{
		p*=(1+( 1. / pow(i, 1./4) ));
	}

	cout << "p: " << p << endl;

}

void task3(int n)
{
	// s = i=1..n E a^2i, => { ai = i/3 if % 3, !%3 i/i-3)
	double s = 0;

	for(int i = 1; i < n; i++)
	{
		if(i%3==0)
		{
			s+=i/3.;
		}
		else
		{
			s+=i/(i-3.);
		}

	}

	cout << "s: " << s << endl;

}

void task4()
{
	string input;
	cout << "Please, enter string: ";
	getline(cin, input);
	if (input.length() > 0 && input[input.length() - 1] == '@')
	{
		for (auto& c : input)
		{
			if (c == 'A' || c == 'a')
			{
				continue;
			}
			cout << c;
		}
	}

}

void task5()
{
	int m;
	int n;
	int k;
	int l;

	bool col1;
	bool col2;


	cout << "Enter m: ";
	cin  >> m;
	cout << "Enter n: ";
	cin  >> n;
	cout << "Enter k: ";
	cin  >> k;
	cout << "Enter l: ";
	cin  >> l;


	if(m%2==0)
	{
		if(n%2==0)
		{
			col1 = false;
		}
		else
		{
			col1 = true;
		}
	}
	else
	{
		if(n%2==0)
		{
			col1 = true;
		}
		else
		{
			col1 = false;
		}
	}

	if(k%2==0)
	{
		if(l%2==0)
		{
			col2 = false;
		}
		else
		{
			col2 = true;
		}
	}
	else
	{
		if(l%2==0)
		{
			col2 = true;
		}
		else
		{
			col2 = false;
		}
	}

	if(col1==col2)
	{
		cout<<"Same color" << endl;
	}
	else
	{
		cout<<"Diff color" <<endl;
	}


}

void task6()
{
	string input;
	cout << "Please, enter string: ";
	getline(cin, input);
	istringstream buf(input);
	istream_iterator<string> beg(buf), end;
	vector<string> tokens(beg, end);
	vector<int> numbers;
	for (auto word : tokens)
	{
		numbers.push_back(stoi(word));
	}
	int n;
	cout << "Enter position where to find neighbors: ";
	cin >> n;
	while (cin.fail() || n > numbers.size() || n < 0)
	{
		cout << "Try again!: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
	int neigh = 0;

	if (numbers[n - 1] >= 0)
	{
		if (n-2 >= 0 && numbers[n - 2] < 0)
			neigh++;
		if (n < numbers.size() && numbers[n] < 0)
			neigh++;
	}
	if (numbers[n - 1] < 0)
	{
		if (n - 2 >= 0 && numbers[n - 2] >= 0)
			neigh++;
		if (n < numbers.size() && numbers[n] >= 0)
			neigh++;
	}
	
	cout << "Number " << numbers[n - 1] << " has " << neigh << " neighbors";
}

void task7()
{
	cin.clear();
	cin.ignore(256, '\n');
	string input;
	cout << "Please, enter string: ";
	getline(cin, input);
	string abc  = "abcdefghijklmnopqrtsuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string nums = "0123456789";
	int numbers = 0;
	int latin   = 0;

	if (input.length() > 0 && input[input.length() - 1] == '$')
	{
		for (auto& ch : input)
		{
			if (abc.find(ch) != string::npos)
			{
				latin++;
				continue;
			}
			if (nums.find(ch) != string::npos)
			{
				numbers++;
				continue;
			}
		}
	}
	cout << "String has " << numbers << " numbers and " << latin << " signs!";

}

void task8(int i, int k)
{
	int z;

	if(i%k==0)
	{
		z = i-k;
	}
	else if(k%i==0)
	{
		z = k-i;
	}
	else
	{
		z = k+i;
	}

	cout << "z: " << z << endl;
}

void task9()
{
	int m;
	int n;
	int k;
	int l;

	bool isHitted = false;

	cout << "Enter m: ";
	cin  >> m;
	cout << "Enter n: ";
	cin  >> n;
	cout << "Enter k: ";
	cin  >> k;
	cout << "Enter l: ";
	cin  >> l;

	if(m==k)
	{
		isHitted = true;
	}
	else if(n==l)
	{
		isHitted = true;
	}
	else if (abs(m-k) == abs(n-l))
	{
		isHitted = true;
	}

	if (isHitted)
	{
		cout << "Figure can be hitted!" << endl;
	}
	else
	{
		cout << "Figure is in safe position!" << endl;
	}

}

void task10()
{
	cin.clear();
	cin.ignore(256, '\n');
	int n;
	cout << "Enter number: ";
	cin >> n;
	while (cin.fail())
	{
		cout << "Try again!: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
	//[2;5] and [-1;1]
	bool s = n >= -1 && n <= 1 || n >= 2 && n <= 5;

	cout << "S = " << s;
}

void task11(int n)
{
	for(int i = n; i>0; i--)
	{
		if(n%i==0)
		{
			cout << "Divider: " << i << endl;
		}
	}

}

void task12()
{
		double a, b;
	double result;
	cout << "Enter a: ";
	cin >> a;
	while (cin.fail())
	{
		cout << "Invalid input\n";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter a: ";
		cin >> a;
	}
	cin.clear();
	cin.ignore(256, '\n');
	cout << "Enter b: ";
	cin >> b;
	while (cin.fail())
	{
		cout << "Invalid input\n";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter b: ";
		cin >> b;
	}
	cin.clear();
	cin.ignore(256, '\n');
	int oper;

	cout << "\nChoose arithmetic operation\n1) Add\n2) Substract\n3) Multiply\n4) Divide\nInput: ";
	cin >> oper;
	switch (oper)
	{
	case 1:
		result = a + b;
		break;
	case 2:
		result = a - b;
		break;
	case 3:
		result = a * b;
		break;
	case 4:
		result = a / b;
		break;
	default:
		cout << "Invalid input";
		return;
		break;
	}

	cout << "Result: " << result << endl;
}

void task13()
{

	for(double x = -0.4; x <= 1.3; x+=0.1)
	{
		if(x<=0.5)
		{
			cout << 1 << endl;
		}
		else
		{
			double fx = sin( (x-1)*M_PI_2 );
			cout << fx << endl;
		}
	}
}

void task14(int x)
{
	double y2 = x;
	double y1 = 0;

	while(abs(y2-y1) > 0.00005)
	{
		y1 = y2;

		y2 = 0.5*(y1+ x/y1);

	}

	cout << "Sqrt " << x << " = " << y2 << endl;

}

void task15(int n)
{
	int sum = 0;

	while(n!=0)
	{
		sum+=n%10;
		n /= 10;
	}

	cout << "Sum: " << sum << endl;

}

int main()
{
	task1();
	task2(8);
	task3(11);
	task4();
	task5();
    task6();
    task7();
	task8(5,25);
	task9();
    task10();
	task11(10);
	task12();
	task13();
	task14(135);
	task15(33335);

	return 0;
}



