#include <iostream>
using namespace std;

void powerSet(int k, int n, char data[], bool *include, int cnt )
{
	if (k == n) {
		for (int i = 0; i < n; i++)
			if (include[i]) cout << data[i] << " ";
		cout << endl;
		
		return;
	}
	include[k] = false;
	powerSet(k + 1,n,data,include,cnt);
	include[k] = true;
	powerSet(k + 1,n,data,include,cnt);

}
int main()
{	
	char data[] = { 'a','b','c','d','e' };
	int cnt=0;
	int n = sizeof(data);
	bool *include = new bool[n];

	powerSet(0,n,data,include,cnt);

	
	return 0;
}