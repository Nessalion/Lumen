#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int e_main, n, f, j, i, ret;

int privat_key(int ic, int ic_1)
{
	int a[88] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,
		89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,
		199,211,223,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,
		389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503 };
	j = 0;
	int size = 0;
	int a_p = a[ic];
	int a_q = a[ic_1];
	n = a_p * a_q;
	f = (a_p - 1) * (a_q - 1);
	for (i = 0; i < 87; i++)
	{
		if ((a[i] < f) && (a[i] % f != 0))
		{
			size++;
		}

	}

	int* e = new int[size];

	for (i = 0; i < 87; i++)
	{
		if ((a[i] < f) && (a[i] % f != 0))
		{
			e[j] = a[i];
			j++;
		}

	}
	srand(time(NULL));
	if (size == 0)
	{
		privat_key(rand() % 88, rand() % 88);
		return  ret;
	}
	else {
		int jk = rand() % size;
		if (jk <= 0) {
			jk *= -1;
		}
		e_main = e[jk];

		int size_1 = 0;
		long  d;
		//cout << LONG_MAX;
		j = 0;
		long max_d = 270000;
		for (d = 2; d < max_d; d++)
		{
			if (((d * e_main) % f) == 1)
			{
				size_1++;
			}
		}
		if (size_1 > 400)
		{
			size_1 = 400;
		}

		int* d_pr = new int[size_1];
		for (d = 2; d < max_d; d++)
		{
			if ((d * e_main) > f)
			{
				if (((d * e_main) % f) == 1)
				{
					d_pr[j] = d;
					j++;
					if ((size_1 == 400) && (j == 400))
					{
						break;
					}
				}
			}
		}

		srand(time(NULL));
		if (size_1 == 0) {
			privat_key(rand() % 88, rand() % 88);
			return  ret;

		}
		else
		{
			int pr = rand() % size_1;
			if (pr <= 0) {
				pr *= -1;
			}


			cout << "Приватный ключ: (" << d_pr[pr] << "," << n << ")" << endl;

		}



	}

}

void key(int ic_1, int ic)
{
	srand(time(NULL));
	i = 0;
	j = 0;
	int a[88] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,
		89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,
		199,211,223,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,
		389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503 };

	int index_a = 0;



	int a_p;
	int a_q;


	a_p = a[ic];
	a_q = a[ic_1];

	n = a_p * a_q;
	f = (a_p - 1) * (a_q - 1);

	cout << "Публичный ключ: (" << e_main << "," << n << ")" << endl;

}

void encrypto() {

}





int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	const int size_1 = 2;
	int ic;
	int ic_1;



	ic = rand() % 88;
	ic_1 = rand() % 88;





	privat_key(ic, ic_1);
	key(ic, ic_1);


}