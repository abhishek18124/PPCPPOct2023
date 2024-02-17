#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || i == -1 || j == n || j == -1) {
		// rat has gone outside the maze
		return;
	}

	if (maze[i][j] == 'X') {
		// you've reached a blocked cell
		return;
	}

	if (i == m - 1 and j == n - 1) {
		// you've reached the destination i.e you've found a path
		path[m - 1][n - 1] = '1';
		printPath(path, m, n);
		path[m - 1][n - 1] = '0';
		return;
	}

	// recursive case

	path[i][j] = '1'; // use the cell
	maze[i][j] = 'X'; // block the cell

	for (int k = 0; k < 4; k++) {
		f(maze, path, m, n, i + dx[k], j + dy[k]);
	}

	path[i][j] = '0'; // unuse the cell
	maze[i][j] = '0'; // unblock the cell

}

int main() {

	char maze[][10] = {
		"0X00",
		"000X",
		"X0X0",
		"X00X",
		"XX00"
	};

	char path[][10] = {
		"0000",
		"0000",
		"0000",
		"0000",
		"0000"
	};

	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}
