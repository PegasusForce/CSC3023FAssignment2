/* 
 * File:   Node.h
 * Author: khagendra
 *
 * Created on 07 April 2014, 8:54 PM
 */

#ifndef NODE_H
#define	NODE_H
#include "counter.h"
class Node:public sjp::counter<Node> {
public:
    //Default constructor
    Node();
    //Standard constructor
    Node(int nc);
    //Copy constructor
    Node(const Node& orig):_maxChildren(orig._maxChildren),_children(orig._children),_numChildren(orig._numChildren),_value(orig._value){};
    //Move Constructor
    Node(const Node&& orig):_maxChildren(std::move(orig._maxChildren)),_children(std::move(orig._children)),_numChildren(std::move(orig._numChildren)),_value(std::move(orig._value)){};
    //Copy assignment operator
    Node &operator=(const Node& orig);
    //Move assignment operator
    Node &operator=(const Node&& orig);
    //Destuctor
    virtual ~Node();
    
    virtual void to_string(std::stringstream ss);
private:
    Node** _children;
    int _numChildren=0;
    int _maxChildren;
    char _value;
};

#endif	/* NODE_H */

