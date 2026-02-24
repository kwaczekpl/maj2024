#include <iostream>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


void zad41()
{
	ifstream pl{ "liczby.txt" }; //liczby_przyklad.txt

	const int w1S = 3000;  //200 //3000
	const int w2S = 20;
	int w1[w1S];
	int w2[w2S];
	
	for (int i = 0; i < w1S; i++)
	{
		pl >> w1[i];
		//cout << w1[i] << " ";
	}
	for (int i = 0; i < w2S; i++)
	{
		pl >> w2[i];
		//cout << w2[i] << " ";
	}
	
	int licz = 0;

	
		for (int j = 0; j < w1S; j++)
		{
			for (int i = 0; i < w2S; i++)
			{
				if (w2[i] % w1[j] == 0)
				{
					licz++;
					break;
				}
			}
		}
	
	cout << licz;
}

void zad42()
{
	ifstream pl{ "liczby.txt" }; //liczby_przyklad.txt

	const int w1S = 3000;  //200 //3000
	const int w2S = 20;
	vector <int> w1;
	vector <int> w2;
	int insW1;
	int insW2;

	for (int i = 0; i < w1S; i++)
	{
		pl >> insW1;
		w1.push_back(insW1);
		//cout << w1[i] << " ";
	}
	for (int i = 0; i < w2S; i++)
	{
		pl >> insW2;
		w2.push_back(insW2);
		//cout << w2[i] << " ";
	}

	sort(w1.rbegin(), w1.rend());

	cout << w1.at(100);

	/*for (int i : w1)
	{
		cout << i << " ";
	}*/
}

void zad43()
{
	ifstream pl{ "liczby.txt" }; //liczby_przyklad.txt

	const int w1S = 3000;  //200 //3000
	const int w2S = 20;
	vector <int> w1;
	vector <int> w2;
	int insW1;
	int insW2;

	for (int i = 0; i < w1S; i++)
	{
		pl >> insW1;
		w1.push_back(insW1);
		//cout << w1[i] << " ";
	}
	for (int i = 0; i < w2S; i++)
	{
		pl >> insW2;
		w2.push_back(insW2);
		//cout << w2[i] << " ";
	}

	
	sort(w1.begin(), w1.end());

	for (int i = 0; i < w2S; i++)
	{
		int liczba = w2[i];

		for (int j = 0; j < w1S; j++)
		{
			if (liczba % w1[j] == 0)
			{
				liczba /= w1[j];
			}
			if (liczba == 1)
			{
				cout << w2[i] << " ";
				break;
			}
		}
	}
	


	/*for (int i : w1)
	{
		cout << i << " ";
	}*/
}

void zad44()
{
	ifstream pl{ "liczby.txt" }; //liczby_przyklad.txt

	const int w1S = 3000;  //200 //3000
	const int w2S = 20;
	vector <int> w1;
	vector <int> w2;
	int insW1;
	int insW2;

	for (int i = 0; i < w1S; i++)
	{
		pl >> insW1;
		w1.push_back(insW1);
		//cout << w1[i] << " ";
	}
	for (int i = 0; i < w2S; i++)
	{
		pl >> insW2;
		w2.push_back(insW2);
		//cout << w2[i] << " ";
	}

	double srd = 0;
	double maxsrd = 0;
	double pLicz = 0;
	double maxpLicz = 0;
	double sumaL = 0;
	double ileLiczb = 0;
	double ileLiczbmax = 0;

	for (int i = 0; i < w1S; i++)
	{
		maxpLicz = w1[i];
		for (int j = i; j < w1S; j++)
		{
			ileLiczb++;
			sumaL = sumaL + w1[j];
			if (ileLiczb > 49)
			{
				srd = sumaL / ileLiczb;
				if (maxsrd < srd)
				{
					
					ileLiczbmax = ileLiczb;
					
					maxsrd = srd;
					pLicz = maxpLicz;
				}
			}
		}
		ileLiczb = 0;
		sumaL = 0;
	}

	cout << setprecision(16) << maxsrd << " " << ileLiczbmax << " " << pLicz;


	/*for (int i : w1)
	{
		cout << i << " ";
	}*/
}

int main()
{
	//zad41();
	//zad42();
	//zad43();
	zad44();
}

	