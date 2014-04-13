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
    Node(const Node& orig):_maxChildren(orig._maxChildren),_children(orig._children),_numChildren(orig._numChildren),_value(orig._value){/* std::cout<<"Copying Node "<<rhs._value<<": "<<&rhs<<"->"<<this<<std::endl;*/}
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
    void to_string(std::stringstream& ss){}
    ~Compound();
    Compound(const Compound& orig);
    Compound(const Compound&& orig);
};

class Expression: public Node{
public:
    Expression(std::string lhs);
    Expression(std::string lhs,std::string mid);
    Expression(std::string lhs, std::string mid, std::string rhs);
    Expression(const Expression& exp,int dummy);
    Expression(const Expression& lhs,std::string mid,std::string rhs);
    Expression(const Expression& lhs,std::string mid, const Expression& rhs);
    Expression(std::string lhs,std::string mid, const Expression& rhs);
    void to_string(std::stringstream& ss){}
    ~Expression();
    Expression(const Expression& orig):Node(orig){}
    Expression(const Expression&& orig):Node(orig){}
};

class Statement: public Node{
public:
    Statement(std::string var,std::string mid, const Expression& exp);
    void to_string(std::stringstream& ss){}
    ~Statement();
};

class If: public Node{
public:
    If(const Expression& ex, const Compound& tru, const Compound& fals);
    void to_string(std::stringstream& ss){}
    ~If();
    
};

class While:public Node{
public:
    While(const Expression& exp, const Compound& comp);
 void to_string(std::stringstream& ss){}
 ~While();
};

class FunctionCall: public Node{
public:
   FunctionCall(std::string var, int num);
   void to_string(std::stringstream& ss){}
   ~FunctionCall();
};
#endif	/* NODE_H */

