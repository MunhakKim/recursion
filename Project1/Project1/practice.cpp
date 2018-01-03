#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	double mealCost = 0;
	int tipPercent = 0;
	int taxPercent = 0;
	double tip, tax, result;

	cin >> mealCost;
	cin >> tipPercent;
	cin >> taxPercent;

	tip = mealCost * 0.01*tipPercent;
	tax = mealCost * 0.01*taxPercent;
	
	result = mealCost + tip + tax;

	cout << "The total meal cost is " << round(result) << " dollars." << endl;
	

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
