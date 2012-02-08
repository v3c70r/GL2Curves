#ifndef LINE_H
#define LINE_H
#include <GL/glut.h>
class Line
{
private:
    int x0, y0; //start point 
    int x1, y1; //end point
    char startCutCode;
    char endCutCode;
public:
    void setStartPoint(int x, int y)
    {
        x0 = x; 
        y0 = y;
    }
    void setEndPoint(int x, int y)
    {
        x1 = x;
        y1 = y;
    }
    void swapStartEnd()
    {
        int temp = x0;
        x0 = x1;
        x1 = temp;
        temp = y0;
        y0 = y1;
        y1 = temp;
        char tempCutCode = startCutCode;
        startCutCode = endCutCode;
        endCutCode = tempCutCode;
    }
    void getCutCode(int, int, int, int);
    void cut(int, int, int, int);
    void glDraw() const;
    
};






#endif
