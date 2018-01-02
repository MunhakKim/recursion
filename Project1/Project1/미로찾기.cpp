#include <iostream>
using namespace std;

class Maze
{
public:
	bool findMazePath(int x, int y);
	int maze[8][8] = {
		{ 0,0,0,0,0,0,0,1 },
		{ 0,1,1,0,1,1,0,1 },
		{ 0,0,0,1,0,0,0,1 },
		{ 0,1,0,0,1,1,0,0 },
		{ 0,1,1,1,0,0,1,1 },
		{ 0,1,0,0,0,1,0,1 },
		{ 0,0,0,1,0,0,0,1 },
		{ 0,1,1,1,0,1,0,0 }
	};
	int N = 8;
	int PATHWAY_COLOR = 0;
	int WALL_COLOR = 1;
	int BLOCKED_COLOR = 2;        //visited이며 출구까지의 경로상에 있지 않음이 밝혀진 cell
	int PATH_COLOR = 3;			  //visited이며 출구로 가는 경로가 될 가능성이 있는 cell 
};

bool Maze::findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	else if (maze[x][y] != PATHWAY_COLOR)
		return false;
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATH_COLOR;
		return true;
	}
	else {
		maze[x][y] = PATH_COLOR;
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1) || findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;
		}
		maze[x][y] = BLOCKED_COLOR;
		return false;
	}
}

int main()
{
	Maze m;
	cout<<m.findMazePath(0, 0)<<endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << m.maze[i][j];
		}
		cout << endl;
	}
	
	return 0;
}