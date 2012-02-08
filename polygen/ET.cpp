#include "ET.h"
#include <GL/glut.h>
/* This function insert by the order of x and k * increasing by x in increasing order * if xs are same, order by k in increasing order
 */
void ET::insertByOrder(ETNode *node)
{
    ETNode* elem = head;
    while(elem->next != NULL)
    {
        if((node->x < elem->next->x) ||
                ((node->x == elem->next->x && node->k < elem->next->k)))
        {
            //insert node after elem
            node->next = elem->next;
            elem->next = node;
            return;
        }
        else
            elem = elem->next;
    }
    //loop finished, add node to the last elem
    node->next = NULL; 
    elem->next = node;
}

void ET::mergeWithET(ET sourceET)
{
    ETNode* elem = sourceET.head->next;
    ETNode* nextElem = sourceET.head->next;
    while(nextElem != NULL)
    {
        nextElem = nextElem->next;
        this->insertByOrder(elem);
        elem = nextElem;
    }
}

/*
 * Check if any node in the list meet yMax
 * if so, remove it from list
 * */
void ET::checkYMax(int y)
{
    ETNode* elem = head;
    ETNode* elemToDel;
    while(elem->next != NULL && elem != NULL)
    {
        if(elem->next->yMax == y)
        {
            elemToDel = elem->next;
            elem->next = elemToDel->next;
            delete elemToDel;
            continue; }
        elem = elem->next;
    }
}


/*
 * Generate a new AET from previous AET item
 */
void ET::generateFromPreAET(ET preET)
{
    ETNode* index = preET.head->next;
    ETNode* preIndex = this->head;
    while(index != NULL)
    {
        ETNode *elem = new ETNode;
        elem->x = (index->x)+(index->k); 
        elem->yMax = index->yMax;
        elem->k = index->k;
        preIndex->next = elem;
        index = index->next;
        preIndex = elem;
    }
}

void ET::printET() const
{
    ETNode* elemIndex = head->next;
    while(elemIndex != NULL)
    {
        std::cout<<"yMax="<<elemIndex->yMax<<"\tx="<<elemIndex->x<<"\t1/k="<<elemIndex->k<<"\t|\t";
        elemIndex=elemIndex->next;
    }
}

//destructor


            
            


