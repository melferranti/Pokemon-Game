#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

Vector2D :: Vector2D(double in_x, double in_y)
:x(in_x), y(in_y)  {  }

Vector2D :: Vector2D()
:x(0.0), y(0.0)  {  }

Vector2D :: ~Vector2D()  {  }

Vector2D operator*(Vector2D v1, double d)  {
  double x = v1.x * d;
  double y = v1.y * d;
  return Vector2D(x, y);
}

Vector2D operator/(Vector2D v1, double d)  {
  double x = v1.x / d;
  double y = v1.y / d;
  return Vector2D(x, y);
}

ostream& operator<<(ostream& COUT, const Vector2D& vector2D) {
  COUT << "<" << vector2D.x << ", " << vector2D.y << ">";
  return COUT;
}