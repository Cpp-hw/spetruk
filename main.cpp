#include <iostream>
#include <string>
#include <sstream>
#include <map>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;


void drawTriangle(int** triangle, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << string(length - i, ' ');
		for (int j = 0; j <= i; j++)
		{
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
}

long long fact(int n)
{
    long long result = 1;

	if (n == 0 || n == 1)
		return result;
	for(int i = 2; i <= n; i++)
		result*=i;
	return result;
}

void pascalsTriangle(int n)
{
	for(int row = 0; row < n; row++)
	{
		cout << string(n-row, ' ');
		for(int k = 0; k <= row; k++ )
		{
			long long elem = fact(row)/(fact(row-k)*fact(k));
			cout << elem << " ";
		}
		cout << endl;
	}
}

void validPalindrome(string text)
{
	int length = text.length()-1;
	bool isPalindrome = false;
	string abc = "abcdefghijklmnopqrstuvwxyz";


	for(int i = 0; i <= length; i++)
	{
		if (abc.find(text[i] != string::npos) && abc.find(text[length-i] != string::npos))
		{
			if(text[i] != text[length-i])
				break;
			if(i==length)
				isPalindrome = true;
		}
	}

	cout << text << " is palindrome: " << isPalindrome << endl;

}

void zigZagConversion(string s, int n)
{
	string result = "";
	int length = s.length();
	int delta0 = n + (n-2);
	for(int depth = n; depth > 0; depth--)
	{
		int delta = depth + (depth-2);
		for(int cur = n-depth; cur < length; cur+=delta0)
		{
			result+=s[cur];
			if(cur+delta < length && delta<delta0 && delta != 0)
			{
				result+=s[cur+delta];
			}
		}
	}
	cout << result;
}

void wordPattern()
{
	bool result = false;

	string text, pattern;
	cout << "Enter text: ";
	getline(cin, text);
	cout << "Enter pattern: ";
	getline(cin, pattern);

	istringstream stream(text);
	string tmp;

	map<string, int> _text;
	map<char, int>   _pattern;


	int iter = 0;
	while ( stream >> tmp )
	{
		if(pattern.length() <= 0) break;
		_text.insert({ tmp, iter });
		_pattern.insert({ pattern[iter], iter });
		if( _text.find(tmp)->second !=
			_pattern.find(pattern[iter])->second)
			    break;
		iter++;
	}
	if(iter == pattern.length())
		result = true;

	cout << "Pattern is valid: " << result << endl;


}


void sudokuChecker(int board[][9])
{
	int sumOfCol, sumOfRow, sumOfBox = 0;
	bool isValid = true;

	for (int i = 0; i < 9; i++)
	{
		sumOfCol = 0;
		sumOfRow = 0;
		for (int j = 0; j < 9; j++)
		{
			sumOfCol += board[i][j];
			sumOfRow += board[j][i];

			int checkCell = board[i][j];


			for (int k = j; k < 9; k++)
			{
				if (k == j || checkCell == 0) continue;

				if (board[i][k] == checkCell)
				{
					cout << "Check: " << checkCell << " at " << i << " " << j << endl;
					cout << "Duplicate found at: " << i << " " << k << endl;
					isValid = false;
					break;
				}
			}

			for (int k = i; k < 9; k++)
			{
				if (k == i || checkCell == 0) continue;
				if (board[k][j] == checkCell)
				{
					cout << "Check: " << checkCell << " at " << i << " " << j << endl;
					cout << "Duplicate found at: " << k << " " << i << endl;
					isValid = false;
					break;
				}

			}

		}
		if (sumOfCol > 45 || sumOfRow > 45)
		{
			cout << "Sum of col or row > 45" << endl;
			isValid = false;
			break;
		}

	}

	if (isValid)
	{
		for (int row = 0; row <= 6; row+=3)
		{
			for (int col = 0; col <= 6; col+=3)
			{
				sumOfBox = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						sumOfBox += board[row + i][col + j];

						int check = board[row + i][col + j];
						if (check == 0) continue;
						for (int checkI = i; checkI < 3; checkI++)
						{
							for (int checkJ = j; checkJ < 3; checkJ++)
							{
								if (checkI == i && checkJ == j) continue;

								if (check == board[row + checkI][col + checkJ])
								{
									isValid = false;
									break;
								}
							}
						}

					}
				}

				if (sumOfBox > 45)
				{
					isValid = false;
					cout << "Sum > 45" << endl;
					break;
				}

			}
		}
	}



	cout << "Board valid: " << isValid << endl;
}

void triangularAlgo(int** triangle, int length)
{
	int** tmpTriangle = new int*[length];
	for (int i = 0; i < length; i++)
		tmpTriangle[i] = new int[length];

	for (int i = 0; i < length; i++)
		for (int j = 0; j <= i; j++)
			tmpTriangle[i][j] = triangle[i][j];


	drawTriangle(triangle, length);

	int sum = 0;

	for (int i = length-2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (tmpTriangle[i+1][j] < tmpTriangle[i+1][j+1])
			{
				tmpTriangle[i][j] += tmpTriangle[i+1][j];
			}
			else
			{
				tmpTriangle[i][j] += tmpTriangle[i+1][j+1];
			}
		}
	}

	sum = tmpTriangle[0][0];
	cout << "Sum: " << sum << endl;


	for (int i = 0; i < length; i++)
	{
		delete[] tmpTriangle[i];
	}
	delete[] tmpTriangle;


}

void randTriangularMatrix(int** triangle, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++) 
		{
			triangle[i][j] = INT_MAX;
			if (j <= i)
			{
				triangle[i][j] = rand() % 10;
			}
		}
	}
}

int main()
{
	//pascalsTriangle(5);
	//validPalindrome("stas sats");
	//zigZagConversion("stanislavpetruk", 5);
	//wordPattern();

	int** triangle = new int*[5];
	for (int i = 0; i < 5; i++)
		triangle[i] = new int[5];
	
	randTriangularMatrix(triangle, 5);
	triangularAlgo(triangle, 5);
	for (int i = 0; i < 5; i++)
		delete[] triangle[i];
	delete[] triangle;

	int corBoard[][9] = 
	{
		{ 8,3,5,4,1,6,9,2,7 },
		{ 2,9,6,8,5,7,4,3,1 },
		{ 4,1,7,2,9,3,6,5,8 },
		{ 5,6,9,1,3,4,7,8,2 },
		{ 1,2,3,6,7,8,5,4,9 },
		{ 7,4,8,5,2,9,1,6,3 },
		{ 6,5,2,7,8,1,3,9,4 },
		{ 9,8,1,3,4,5,2,7,6 },
		{ 3,7,4,9,6,2,8,1,5 }
	};

	int inBoard[][9] =
	{
		{ 8,3,5,4,1,6,9,2,7 },
		{ 2,9,6,8,5,7,4,3,1 },
		{ 4,1,7,2,9,3,6,5,8 },
		{ 5,6,9,1,3,4,7,8,2 },
		{ 1,2,3,6,7,8,5,4,9 },
		{ 7,4,8,5,2,9,1,6,3 },
		{ 6,5,2,7,8,1,3,9,4 },
		{ 9,8,1,3,4,5,2,7,6 },
		{ 3,7,4,9,6,2,8,1,1 }
	};
	
	sudokuChecker(corBoard);
	sudokuChecker(inBoard);

	return 0;
}


