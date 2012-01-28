/* FileName: vecLib.cpp
 * Author  : Vector(mcvector.gu@gmail.com) * Description:
 *  This file realize the functions in vecLib.h
 */
#include "vecLib.h"
#include "ET.h" 
#include <iostream>
struct Line; struct Rectangle; struct Polygen;
void Point::glDraw()
{
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}


void Line::glDraw()
{
    glBegin(GL_LINES);
        glVertex2i(start.x, start.y);
        glVertex2i(end.x, end.y);
    glEnd();
}
void Rectangle::glDraw() {

    glRecti(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

void Polygen::setPointPosition(int index, int x, int y)         //change position of an excit point
{
    if(index >= vertex.size())      //index > points in array
        return;
    vertex[index].x = x;
    vertex[index].y = y;
}

void Polygen::glDraw()
{
    int i;
    int n = vertex.size();
    for(i = 1; i <= n; i++)
    {
    drawCoordinate();
    glRectd(vertex[i%n].x-5, vertex[i%n].y-5, vertex[i%n].x+5, vertex[i%n].y+5);
    glBegin(GL_LINES);
            glVertex2i(vertex[i-1].x, vertex[i-1].y);
            glVertex2i(vertex[i%n].x, vertex[i%n].y);
    glEnd();
    }

}

int Polygen::selectPoint(int x, int y)
{
    for(int i = 0; i<vertex.size(); i++)
    {
        int errX = x - vertex[i].x;
        int errY = y - vertex[i].y;
        if((errX <= 5 && errX >= -5) && (errY <=5 && errY >= -5))
            return i;
    }
    return -1;
}

void Polygen::drawCoordinate()
{
    void *font = GLUT_BITMAP_8_BY_13;
    for(int i=0; i<vertex.size(); i++)
    {
        char text[32];
        sprintf(text, "(%d, %d)", (int)vertex[i].x, (int)vertex[i].y);
        glRasterPos2d(vertex[i].x-10, vertex[i].y+5);
        for(int j=0; text[j] != '\0'; j++)
        {
            glutBitmapCharacter(font, text[j]);
        }
    }
    
}

//fill this polygen with RGB below 
void Polygen::glFill(int r, int g, int b)
{
    glColor3d(r, g, b);
    if(vertex.size() < 3)
        return;
    //find highest and lowest point of polygen
    int yMax = vertex[0].y;
    int yMin = vertex[0].y;
    for(int i=1 ; i < vertex.size(); i++)
    {
        if (vertex[i].y > yMax)
            yMax = vertex[i].y;
        if (vertex[i].y < yMin)
            yMin = vertex[i].y;
    }
    //std::cout<<yMax<<"  "<<yMin<<endl;
    ET *ETList = new ET[yMax-yMin+1];
    ET *AETList = new ET[yMax - yMin + 1];
    //add all elements into ETList
    for(int i = 0; i < vertex.size(); i++)
    {
       ETNode *elem = new ETNode;       //build an element
       Point start = vertex[i]; 
       Point end = vertex[(i+1)%vertex.size()];
       if(start.y == end.y) continue;
       elem->k = ((double)(start.x - end.x))/((double)(start.y - end.y));
       if(start.y < end.y)
       {
           elem->x = start.x;
           elem->yMax = end.y - yMin;
           ETList[start.y-yMin].insertAfterHead(elem);
       }
       else
       {
           elem->x = end.x;
           elem->yMax = start.y - yMin;
           ETList[end.y-yMin].insertAfterHead(elem);
       }
       
    }
    //debug output ET list
    /*
    for(int i=0; i <= yMax-yMin; i++)
    {
        if(!ETList[i].isEmpty())
        {
            ETList[i].printET();

            std::cout<<std::endl;
        }
    }
    */


    for(int i = 0; i <= yMax - yMin; i++)
    {
        //build new AET entry from previous AET entry
        if(i > 0)
            AETList[i].generateFromPreAET(AETList[i-1]);
        //if ET list is not empty, merge it
        if(!ETList[i].isEmpty())
            AETList[i].mergeWithET(ETList[i]);

        //check if elem meet yMax;
        AETList[i].checkYMax(i);
        //draw x, i+yMin 
        /*
        std::cout<<i<<endl;
        AETList[i].printET();
        std::cout<<std::endl;
        */
        

        //draw
        bool draw = false;
        ETNode *elem = AETList[i].exposeHead()->next;
        while(elem != NULL)
        {
            for(int j=elem->x; j < elem->next->x; j++)
            {
                glBegin(GL_POINTS);
                    glVertex2i(j, i+yMin);
                glEnd();
            }
            elem = elem->next->next;
        }
    }
    /*
    for(int i=0; i <= yMax-yMin; i++)
    {
        {
            ETNode *elem = AETList[i].exposeHead()->next;
            while(elem != NULL)
            {
                std::cout<<elem->x<<", "<<i+yMin<<", "<<elem->k<<'\t';
                elem = elem->next;
            }
            std::cout<<std::endl;
        }
    }
    */

}

