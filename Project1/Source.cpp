#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* c, const int size, const int Low, const int High,int i)
{
		c[i] = Low + rand() % (High - Low + 1);
		if (i < size-1)
			Create(c, size, Low, High, i + 1);
}
void Sum(int* c, int size, int& S, int& k, int i)
{
	if ((c[i] % 2 != 0 || c[i] > 0)) 
	{
		S += c[i];
		k++;
		c[i] = 0;
	}
	if (i < size - 1)
		return Sum(c, size, S, k, i + 1);
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 27;
	int c[n];
	int Low = -35;
	int High = 25;
	Create(c, n, Low, High, 0);
	cout << setw(4) << "c[] = {";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << c[i] << ",";
	}
	cout << "}" << endl;
	cout << endl;
	int S = 0;
	int k = 0;
	Sum(c, n, S, k, 0);
	cout << "Number = " << k << endl;
	cout << setw(4) << "Sum = " << S << endl;
	cout << endl;
	cout << setw(4) << "c[] = {";
	for (int d = 0; d < n; d++)
	{
		cout << setw(4) << c[d] << ",";
	}
	cout << "}" << endl;
	return 0;
}