#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void zad1()
{
	int pMaxcurr = 0;
	int pMax = 0;
	int pMin = 0;
	int suma = 0;
	int sumMax = 0;

	int a[] = {2, -3, 1, -7, 4, -2, -1, 5, -3, 2, -1};

	for (int i = 0; i < 11; i++)
	{
		pMaxcurr = a[i];
		for (int j = i; j < 11; j++)
		{
			suma = suma + a[j];
			if (sumMax < suma)
			{
				sumMax = suma;
				pMin = a[j];
				pMax = pMaxcurr;
			}
		}
		suma = 0;
	}

	cout << pMax << " " << pMin << " " << sumMax;
}

void zad13()
{
	ifstream plik{ "dane1_3.txt" };

	const int n = 1000;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		plik >> a[i];
	}

	int pMaxcurr = 0;
	int pMax = 0;
	int pMin = 0;
	int suma = 0;
	int sumMax = 0;

	for (int i = 0; i < n; i++)
	{
		pMaxcurr = a[i];
		for (int j = i; j < n; j++)
		{
			suma = suma + a[j];
			if (sumMax < suma)
			{
				sumMax = suma;
				pMin = a[j];
				pMax = pMaxcurr;
			}
		}
		suma = 0;
	}

	cout << pMax << " " << pMin << " " << sumMax;
}

void zad14()
{

	ifstream plik{ "dane1_4.txt" };

	const int n = 100'000;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		plik >> a[i];
	}

	int pMaxcurr = 0;
	int pMax = 0;
	int pMin = 0;
	int suma = 0;
	int sumMax = 0;
	int maxIndex = 0;
	int minIndex = 0;

	for (int i = 0; i < n; i++)
	{
		pMaxcurr = a[i];
		
		for (int j = i; j < n; j++)
		{
			suma = suma + a[j];
			if (sumMax < suma)
			{
				sumMax = suma;
				pMin = a[j];
				pMax = pMaxcurr;
				maxIndex = i + 1;
				minIndex = j + 1;
			}
		}
		suma = 0;
	}

	cout << maxIndex << " " << minIndex;
}

void zad23()
{
	ifstream plik{ "dane2_3.txt" };

	string nawias;
	int sum = 0;
	int sumMax = 0;
	while (plik >> nawias)
	{
		for (int i = 0; i < nawias.size(); i++)
		{
			if (nawias[i] == '[')
			{
				sum++;
				if (sumMax < sum)
				{
					sumMax = sum;
				}
			}
			if(nawias[i] == ']')
			{
				sum--;
				
			}
			
		}
		cout << sumMax << '\n';
		sum = 0;
		sumMax = 0;
	}
}

void zad24()
{
	ifstream plik{ "dane2_4.txt" };

	string nawias;
	
	while (plik >> nawias)
	{
		int balans = 0;
		bool poprawne = true;
		for (int i = 0; i < nawias.size(); i++)
		{
			if (nawias[i] == '[')
			{
				balans++;
			}
			else
			{
				balans--;

			}
			if (balans < 0)
			{
				poprawne = false;
				break;
			}
		}
		if (poprawne && balans == 0)
		{
			cout << "tak" << '\n';
		}
		else
		{
			cout << "nie" << '\n';
		}
	
	}
}

void zad3()
{
	ifstream plik{ "dane3.txt" };
	int a;
	int b;
	int min1 = 9999;
	int min2 = 99999;
	while (plik >> a >> b)
	{
		int dzialanie = (b - a) + 1;
		if (min1 > dzialanie)
		{
			min2 = min1;
			min1 = dzialanie;
		}
		else if (dzialanie < min2)
		{
			min2 = dzialanie;
		}

	}

	cout << min1 << " " << min2;
}

void zad32()
{
	ifstream plik{ "dane3.txt" };
	int a;
	int b;
	int maks = 0;
	int makl = 0;
	map<int, int> licz;

	while (plik >> a >> b)
	{
		int dzialanie = (b - a) + 1;
		
		licz[dzialanie]++;
	}

	for (int i = 0; i < 2023; i++)
	{
	
		if (maks < licz[i])
		{
			maks = licz[i];
		}
		if (maks == licz[i])
		{
			makl = i;
		}

	}

	cout << makl << " " << maks;
	/*for (auto i : licz)
	{
		cout << i.first << " " << i.second << '\n';
	}*/
}

//bool comp(vector<pair<int, int>> x, vector<pair<int, int>> y)
//{
//	return();
//}

void zad33()
{
	ifstream plik{ "dane3.txt" };
	int k = 0;
	vector<int> a;
	vector<int> b;
	vector<pair<int,int>> ab;
	int af;
	int bf;
	for (int i = 0; i < 2023; i++)
	{
		plik >> af >> bf;
		
		a.push_back(af);
		b.push_back(bf);
	}
	
	//sort(ab.begin(), ab.end(), comp);
		
	int dlugosc = 0;
	int licz = 1;
	int curr = 0;
	for (int i = 0; i < 2023; i++)
	{
		curr = i;
		for (int j = 0; j < 2023; j++)
		{
			if ((a[curr] <= a[j] && b[curr] >= b[j]) && i != j)
			{
				licz++;
				//dlugosc = dlugosc + b[j] - a[j] + 1;
				curr = j;
			}

		}
		//cout << licz << '\n';
		k = max(k, licz);
		licz = 1;
	}

	cout << k;
}

//void zad41()
//{
//	ifstream plik{ "dane4.txt" };
//
//	const int n = 2023;
//	int a[n];
//	
//	for (int g = 0; g < n; g++)
//	{
//		plik >> a[g];
//	}
//
//	int maxi = 0;
//	int licz = 0;		
//	for (int i = 1; i < n; i++)
//	{
//		int v = a[i];
//		int j = i;
//		while ((j > 0) && (v < a[j - 1]))
//		{
//			a[j] = a[j - 1];
//			j = j - 1;
//
//			if (a[i] > a[j] && i > j)
//			{			
//				licz++;
//				maxi = max(licz, maxi);
//
//			}
//
//		}
//		licz = 0;
//		a[j] = v;
//	}
//
//	/*for (auto t : a)
//	{
//		cout << t << '\n';
//	}*/
//	cout << maxi;
//}


void zad41()
{
	ifstream plik{ "dane4.txt" };

	const int n = 2023;
	int a[n];

	for (int g = 0; g < n; g++)
	{
		plik >> a[g];
	}

	int maxi = 0;
	int licz = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (a[i] > a[j] && i > j)
			{
				licz++;
				maxi = max(licz, maxi);

			}

		}
		licz = 0;
	}

	/*for (auto t : a)
	{
		cout << t << '\n';
	}*/
	cout << maxi;
}

void zad4pop3()
{
	ifstream plik{ "dane4.txt" };

	int n = 2023;
	int czyt = 0;
	vector<int> a;
	while(plik >> czyt)
	{
		a.push_back(czyt);
	}

//	sort(a.begin(), a.end());
	int maxi = 0;
	int licz = 0;
	int bigI = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] > a[j] && i > j )
			{
				licz++;
				if (licz > maxi)
				{
					maxi = licz;
					bigI = i;
				}


			}

		}
		licz = 0;
	}

	/*for (auto t : a)
	{
		cout << t << '\n';
	}*/
	cout << bigI + 1;
}
int a[11] = { 10,9,8,7,6,5,4,3,2,1,0 };  //{ 0,2,4,6,8,10,9,7,5,3,1 };
 int zad5(int j)
{
	if (j > 1)
	{
		if (a[j] < a[j - 1])
		{
			int v = a[j];
			a[j] = a[j - 1];
			a[j - 1] = v;
			return zad5(j - 1);
		}
	}
}

 void zad6()
 {
	 ifstream plik{ "dane6przyklad.txt" };
	 map<int, int> a;
	 vector<long> l;
	 for (int i = 2; i < 10; i++)
	 {
		 a[i] = 0;
	 }
	 string n;
	 while (plik >> n)
	 {
		 int maks = 0;

		 for (int i = 0; i < 10; i++)
		 {
			 int t = n[i] - '0';
			 maks = max(t, maks);

		 } 
		 a[maks+1]++;

		 maks = 0;
	 }

	 for (auto i : a)
	 {
		 cout << i.first << " " << i.second << '\n';
	 }
	 
 }
 

int main()
{
	zad6();
	//zad1();
	//zad13();
	//zad14();
	//zad23();
	//zad24();
	//zad3();
	//zad32();
	//zad33();
	//zad41();
	//zad4pop3();

	/*zad5(7);
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << '\n';
	zad5(9);
	for (auto i : a)
	{
		cout << i << " ";
	}*/
	//sort
	/*for (int i = 1; i < 11; i++)
	{
		zad5(i);
	}*/
	//backwards
	/*for (int i = 10; i > 2; --i)
	{
		zad5(i);
	}*/

	/*for (auto i : a)
	{
		cout << i << " ";
	*///}
}