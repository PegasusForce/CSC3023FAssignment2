/* 
 * File:   Node.h
 * Author: khagendra
 *
 * Created on 07 April 2014, 8:54 PM
 */

#ifndef NODE_H
#define	NODE_H
#include "counter.h"
#include <sstream>
class Node:public sjp::counter<Node> {
public:
    //Default constructor
    Node();
    //Standard constructor
    Node(int nc);
    //Copy constructor
    Node(const Node& orig):_maxChildren(orig._maxChildren),_children(orig._children),_numChildren(orig._numChildren),_value(orig._value){};
    //Move Constructor
    Node(Node&& orig):_maxChildren(std::move(orig._maxChildren)),_children(std::move(orig._children)),_numChildren(std::move(orig._numChildren)),_value(std::move(orig._value)){orig._children=nullptr;};
    //Copy assignment operator
    Node &operator=(const Node& orig);
    //Move assignment operator
    Node &operator=(Node&& orig);
    //Destuctor
    virtual ~Node();
    
    virtual void to_string(std::stringstream& ss);
    
    int getNumChildren();
    
    int getMaxChildren();
    
    Node* getChild(int i);
    
private:
    Node** _children;
    int _numChildren=0;
    int _maxChildren;
    std::string _value;
};


#endif	/* NODE_H */

