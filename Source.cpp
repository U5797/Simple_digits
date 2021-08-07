#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool finder(vector<short>& digits, short& p)
{
	for (const auto& q : digits)
	{
		if (q % p == 0)
		{
			return 1;
		}
	}
	return 0;
}
void simplify(vector<short>& digits)
{
	vector<short> simp{ 2,3,5,7,11,13,17,19,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97,101 };
	bool a = 1; unsigned g = 0;
	do
	{
		short p = simp[g++];
		if (!finder(digits, p))
		{
			a = 0; break;
		}
		else
		{
			for (auto b = digits.begin(); b != digits.end();)
			{
				if ((*b) % p == 0 && (*b) != p)
				{
					b = digits.erase(b);
				}
				else b++;
			}
			p = simp[g];
		}

	} while (a);
}
int main()
{
	srand(unsigned(time(0)));
	vector<short> digits;

	unsigned f = 100;
	while (f--)
	{
		digits.push_back(rand() % 110);
	}
	for (const auto& c : digits)
	{
		cout << c << "   ";
	}cout << endl << endl;

	simplify(digits);

	for (const auto& c : digits)
	{
		cout << c << "   ";
	}cout << endl;

	return 0;
}