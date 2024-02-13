#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
#include <iostream>

Point2D :: Point2D(double in_x, double in_y)
:x(in_x), y(in_y)  {  }

Point2D :: Point2D()
:x(0.0), y(0.0)  {  }

Point2D :: ~Point2D()  {  }

double GetDistanceBetween(Point2D p1, Point2D p2)  {
  return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

ostream& operator<<(ostream& COUT, const Point2D& point2D) {
  COUT << "(" << point2D.x << ", " << point2D.y << ")";
  return COUT;
}

Point2D operator+(Point2D p1, Vector2D v1)  {
    Point2D p2;
    p2.x = p1.x + v1.x;
    p2.y = p1.y + v1.y;
    return p2;
}

Vector2D operator-(Point2D p1, Point2D p2)  {
  double x = p1.x - p2.x;
  double y = p1.y - p2.y;
  return Vector2D(x, y);
}