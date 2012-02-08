#ifndef ET_H
#define ET_H
#include <iostream>
struct ETNode
{
    double x;
    int yMax;
    double k;
    ETNode *next;
    //constructor, header
    ETNode()
    {
        x = 0;
        yMax = 0;
        k = 0;
        next = NULL;
    }
};
 
class ET
{
private:
    ETNode* head;       //header
    static int x;
public:
    ET()
    {
        head = new ETNode;
    }
        
    
    void insertByOrder(ETNode *node);
    void insertAfterHead(ETNode *node)
    {
        node->next = head->next;
        head->next = node;
    }
    void mergeWithET(ET ET);
    void checkYMax(int y);
    void generateFromPreAET(ET preET);
    void fillLine(int y);
    void printET() const;
    bool isEmpty() const
    {
        if(head->next == NULL)
            return true;
        else
            return false;
    }
    ETNode* exposeHead() const
    {
        return head;
    }
};


#endif
