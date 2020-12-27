#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int n = 0;
	int m = 0;

	cout << "n = "; cin >> n;
	cout << "m = "; cin >> m;

	int tn = n;
	int tm = m;

	cout << "1) --m-++n : " << --m - ++n << endl;

	n = tn; m = tm;
	cout << "n = " << n << "; " << "m = " << m << endl;
	int tmp = m * n;
	cout << "2) m*n<n++ : m*n = " << m*n << " < " <<  n++ << endl;
	if (tmp < n - 1) cout << "YES\n";
	else cout << "NO\n";



	n = tn; m = tm;
	cout << "n = " << n << "; " << "m = " << m << endl;
	cout << "3) n-- > m++ : n-- = " << n-- << " > " << m++ << endl;
	if (n+1 > m-1) cout << "YES\n";
	else cout << "NO\n";
	cout << endl;
	system("pause");
}