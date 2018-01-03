#include <iostream>
using namespace std;

class queen {
public:
	
	
	int N;
	
	
	int* cols = new int[N + 1];
	
	bool queens(int level);
	bool promising(int level);
};

bool queen::promising(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level]) return false;
		else if (level - i == abs(cols[level] - cols[i])) return false;
	}
	return true;

}

bool queen::queens(int level) {
	if (!promising(level)) return false;
	else if (level == N) { 
		for (int i = 1; i <= N; i++) {
			cout << cols[i] << endl;
		}
		
		return true; 
	}
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (queens(level + 1))
			return true;
	}
	return false;
}

int main()
{
	queen q;
	cin >> q.N;

	q.queens(0);
	
	
	return 0;

}