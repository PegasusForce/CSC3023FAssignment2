/* 
 * File:   Iterator.h
 * Author: khagendra
 *
 * Created on 09 April 2014, 4:22 PM
 */

#ifndef ITERATOR_H
#define	ITERATOR_H
#include "Node.h"
#include <stack>
struct state{
    Node* parent;
    int index;
    
};
class Iterator {
    friend class ParseTree;
private:
    //Default constructor
    Iterator();
    
    //Standard constructor
    Iterator(Node* position);
   
    
    
    Node* node;
    //int i=0;
    std::stack<state> stack;
public:
    
    Iterator(const Iterator& orig):node(orig.node),stack(orig.stack){/*std::cout<<"Copying Iterator: "<<&orig<<"->"<<this<<std::endl;*/};
    virtual ~Iterator();
    Node* operator*(){return node;}
    Iterator& operator++();
    Iterator& operator--();
    bool operator==(const Iterator& rhs){return node==rhs.node;}
    bool operator!=(const Iterator& rhs){return node!=rhs.node;}
    Iterator& operator+(std::size_t distance);
    Iterator& operator-(std::size_t distance);
    std::size_t operator-(const Iterator prev);

};

#endif	/* ITERATOR_H */

