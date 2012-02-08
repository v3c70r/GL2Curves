#include "line.h"
void Line::getCutCode(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight)
{
    startCutCode = 0x00;
    endCutCode = 0x00;
    //check startPoint
    //higher than top
    if(y0 > yTopLeft)   startCutCode |= 0x08;
    //lower than bottom
    else if (y0 < yBottomRight) startCutCode |= 0x04;
    //lefter than left
    if(x0 < xTopLeft)   startCutCode |= 0x01;
    else if(x0 > xBottomRight) startCutCode |= 0x02;
    //check end point
    //higher than top
    if(y1 > yTopLeft)   endCutCode |= 0x08;
    //lower than bottom
    else if (y1 < yBottomRight) endCutCode |= 0x04;
    //lefter than left
    if(x1 < xTopLeft)   endCutCode |= 0x01;
    else if(x1 > xBottomRight) endCutCode |= 0x02;
}

void Line::cut(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight)
{
    //check four edges
    for(int i=0; i < 4 ; i++)
    {
        getCutCode(xTopLeft, yTopLeft, xBottomRight, yBottomRight);
        if( (startCutCode | endCutCode) == 0)
            return;

        if( (startCutCode & endCutCode) != 0)
            setEndPoint(x0, y0);

        if(startCutCode == 0x00)
            swapStartEnd();

        if(startCutCode&0x08)   //higher than top
        {
            x0 = (x1 - x0)*(yTopLeft - y0)/(y1 - y0) + x0;
            y0 = yTopLeft;
        }
        else if(startCutCode&0x04)   //lower than bottom
        {
            x0 = (x1 - x0)*(yBottomRight - y0)/(y1 - y0) + x0;
            y0 = yBottomRight;
        }
        else if(startCutCode&0x01)  //lefter than left
        {
            y0 = (xTopLeft - x0)*(y1-y0)/(x1-x0)+y0; 
            x0 = xTopLeft; 
        }
        else //if(startCutCode&0x02)    righter than right
        {
            y0 = (xBottomRight - x0)*(y1-y0)/(x1-x0)+y0; 
            x0 = xBottomRight; 
        }
    }
}

void Line::glDraw() const
{
    glBegin(GL_LINES);
        glVertex2d(x0, y0);
        glVertex2d(x1, y1);
    glEnd();
}

        

    




    

