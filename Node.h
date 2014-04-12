/* 
 * File:   Node.h
 * Author: khagendra
 *
 * Created on 07 April 2014, 8:54 PM
 */

#ifndef NODE_H
#define	NODE_H
#include <sstream>

#define UNIT_TESTING     // So that we know whether to include our counter class
#include "counter.h"     // Object counter header

class Node
#ifdef UNIT_TESTING
:public sjp::counter<Node> 
#endif
{
public:
    //Default constructor
    Node();
    //Standard constructor
    Node(int nc, std::string v);
    //Copy constructor
    Node(const Node& orig);
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
    
    std::string getValue(){return _value;}
    
    int getMaxChildren();
    
    Node* getChild(int i);
    
    int addChild(const Node& node);
    
protected:
    Node** _children;
    int _numChildren=0;
    int _maxChildren;
    std::string _value;
};
class Compound: public Node{
public:
    Compound(int num);
    void to_string(std::stringstream ss);
};

class Statement: public Node{
    Statement(std::string var,std::string exp);
};

class Expression: public Node{
    
};

class If: public Node{
    
};

class While:public Node{
    
};

class FunctionCall: public Node{
    
};
#endif	/* NODE_H */

