/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	// time : O(n^2)

	int cnt = 0;

	for (Point pivot : points) {

		// find the no. of right angled triangles that are axis parallel around the pivot

		// 1. find the no. of points in the 2D plane whose x coor match pivot.x

		// 2. find the no. of points in the 2D plane whose y coor match pivot.y

		int a = 0; // to track no. of points in the 2D plane whose x coor match pivot.x
		int b = 0; // to track no. of points in the 2D plane whose y coor match pivot.y

		for (Point pt : points) {

			if (pt.x == pivot.x) {
				a++;
			}

			if (pt.y == pivot.y) {
				b++;
			}

		}

		cnt += (a - 1) * (b - 1); // we do a-1, b-1 to avoid counting the pivot

	}

	cout << cnt << endl;


	return 0;
}