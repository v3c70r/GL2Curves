#ifndef POINT2D_H
#define POINT2D_H
#define POINT_WITH_COORDINATE 0
#define POINT_ONLY 1

//define two types of point in drawing

class Point2D
{
private:
    double x;
    double y;
public:
    Point2D(){};
    Point2D(double px, double py){x = px; y = py;} //constructor
    Point2D(const Point2D &other){x = other.x; y = other.y;} //copy constructor
    double getX() const{return x;}
    double getY() const{return y;}
    void setX(double px){ x = px; }
    void setY(double py){ y = py; }

    Point2D operator + (const Point2D &other) const;
    Point2D operator - (const Point2D &other) const;
    Point2D operator * (const Point2D &other) const;
    Point2D operator * (double num) const;
    void glDraw(int type);

};


#endif
