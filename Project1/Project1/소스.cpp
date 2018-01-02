#include <iostream>
using namespace std;

//n!
int factorial(int a) {
	if (a <= 0) return 1;
	else {
		return a * factorial(a - 1);
	}
}

//x의 n제곱근 계산시
double power(double x, int n) {
	if (n == 0) return 1;
	else {
		return x * power(x, n - 1);
	}
}

//fibonacci number
int fibonacci(int n) {
	if (n < 2) return n;
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

//최대공약수(Euclid Method)
double gcd(int m, int n) {
	if (m < n) {
		int tmp = m; m = n; n = tmp; // swap m and n
	}
	if (m%n == 0) return n;
	else return gcd(n, m%n);
}
//최대공약수 다른버전
double gcd2(int m, int n) {
	if (n == 0)	return m;
	else return gcd2(n, m%n);
}


int main()
{
	int n;
	cin >> n;
	int result = factorial(n);
	cout << result << endl;
	return 0;
}