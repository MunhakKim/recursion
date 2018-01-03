#include <iostream>
using namespace std;
#define BACKGROUND_COLOR 0
#define IMANGE_COLOR 1
#define ALREADY_COUNTED 2


class cell {
public:
	int grid[8][8] = {
		{ 1,0,0,0,0,0,0,1 },
		{ 0,1,1,0,0,1,0,0 },
		{ 1,1,0,0,1,0,1,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,1,0,1,0,1,0,0 },
		{ 0,1,0,1,0,1,0,0 },
		{ 1,0,0,0,1,0,0,1 },
		{ 0,1,1,0,0,1,1,1 }
	};
	int countCells(int x, int y) {
		int N = 8;
		
		if (x < 0 || x >= N || y < 0 || y >= N)
			return 0;
		else if (grid[x][y] != IMANGE_COLOR)
			return 0;
		else {
			grid[x][y] = ALREADY_COUNTED;
			return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1) + countCells(x + 1, y + 1) + countCells(x - 1, y) +
				countCells(x + 1, y) + countCells(x - 1, y - 1) + countCells(x, y - 1) + countCells(x + 1, y - 1);

		}
	}
};

int main()
{
	cell c;
	cout << c.countCells(3, 5)<<endl;

	return 0;
}