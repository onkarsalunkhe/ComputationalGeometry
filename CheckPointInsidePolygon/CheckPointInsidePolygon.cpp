// Given a convex 2D polygon and a point.
// Check whether the point lies inside, outside or on the polygon.

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct Point {
	double x;
	double y;
};

double distance(Point a, Point b) {
	/* Finds the square of the distance between 2 points
	@param		a		First point
	@param		b		Second point
	@return		Square of the distance between 2 points
	*/
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double checkOnSameSideCG(Point first, Point second, Point cg, Point pt) {
	/*
	Given the end points of the line segment and the function checks 
	if the given point is on the same side of the Center of Gravity of the polygon or not
	@param		first		First end-point of side
	@param		second		Second end-point of side
	@param		cg			Center of gravity of the Polygon
	@param		pt			Point to check
	@return		double		Returns		+ve		if it is on the same side, 
							Returns		-ve		if it on the opposite side
							Returns		0		if it is on the line segment
	*/
	double cgVal = (cg.x - first.x) * (first.y - second.y) - (cg.y - first.y) * (first.x - second.x);
	double ptVal = (pt.x - first.x) * (first.y - second.y) - (pt.y - first.y) * (first.x - second.x);

	if (ptVal == 0) {
		//if (distance(first, pt) > distance(first, second) || distance(second, pt) > distance(first, second)) 
		if ((distance(first, pt) + distance(second, pt)) > distance(first, second))
		{
			return -1;
		}
		else {
			return 0;
		}
	}
	return (cgVal * ptVal);
};

void checkPoint(vector<Point> plygn, Point pt) {
	
	// Calculates the Center of Gravity of the polygon
	Point cg;
	double sumX = 0;
	double sumY = 0;
	for (auto itr = plygn.begin(); itr < plygn.end(); itr++) {
		 sumX = sumX + (*itr).x;
		 sumY = sumY + (*itr).y;
	}
	cg.x = double(sumX / plygn.size());
	cg.y = double(sumY / plygn.size());

	// Iterates through the polygon vector and checks the val returned from the function checkOnSameSideCG()

	for (auto itr = 0; itr < plygn.size(); itr++) {
		double val;
		if (itr == plygn.size() - 1) {
			val = checkOnSameSideCG(plygn[itr], plygn[0], cg, pt);
		}
		else {
			val = checkOnSameSideCG(plygn[itr], plygn[itr + 1], cg, pt);
		}

		if (val > 0) {
			continue;
		}
		else if (val == 0) {
			cout << "Point lies on the Polygon" << endl;
			return;
		}
		else if (val < 0) {
			cout << "Point lies Outside the Polygon" << endl;
			return;
		}
	}
	cout << "Point lies inside the Polygon" << endl;
	return;

};
void main() {

	//	User input of the vertices of the convex Polygon
	vector<Point> plygn;
	plygn.push_back({ 1,1 });
	plygn.push_back({ 2,1 });
	plygn.push_back({ 2,2 });
	plygn.push_back({ 1,2 });

	//	User input for the point to check 
	Point pt{3,1};

	//	Function call
	checkPoint(plygn, pt);

	return;
}

/*
plygn.push_back({ 1,4 });
plygn.push_back({ 2,2 });
plygn.push_back({ 3,1 });
plygn.push_back({ 5,1 });
plygn.push_back({ 6,2 });
plygn.push_back({ 8,6 });
plygn.push_back({ 8,9 });
plygn.push_back({ 3,1 });
plygn.push_back({ 1,7 });
*/