/* 
 * File:   Node.cpp
 * Author: khagendra
 * 
 * Created on 07 April 2014, 8:54 PM
 */

#include "Node.h"
#include <sstream>

Node::Node() {
}
//Destructor

Node::~Node() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }


    }
    //_children=nullptr;
}
//Copy assignment operator

Node& Node::operator=(const Node& rhs) {
    if (this != &rhs) {
        _children = rhs._children;
        _value = rhs._value;
        _numChildren = rhs._numChildren;
        _maxChildren = rhs._maxChildren;
    }
    return *this;
}
//Move assignment operator

Node& Node::operator=(Node&& rhs) {
    if (this != &rhs) {
        _children = std::move(rhs._children);
        _value = std::move(rhs._value);
        _numChildren = std::move(rhs._numChildren);
        _maxChildren = std::move(rhs._maxChildren);
        rhs._children = nullptr;
    }
    return *this;
}

void Node::to_string(std::stringstream& ss) {
    if (_maxChildren == 0 || _value == "if" || _value == "while") {//Don't print parent nodes except for if statements
        ss << _value;

    }
}
//Standard Constructor

Node::Node(int nc, std::string v) {
    // std::cout<<"Creating Node "<<v<<": "<<this<<std::endl;
    _maxChildren = nc;
    //    Node* array[3]; 

    _children = new Node*[nc];
    for (int i = 0; i < nc; i++) {
        _children[i] = nullptr;
    }

    _value = v;

}

int Node::getNumChildren() {
    return _numChildren;
}

int Node::getMaxChildren() {
    return _maxChildren;
}

Node* Node::getChild(int i) {
    if (i >= 0 && i < _numChildren) {
        return _children[i];
    } else {
        return nullptr;
    }
}

int Node::addChild(const Node& child) {
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] == nullptr) {
            _children[i] = new Node(child);
            _numChildren++;
            return i;
        }
    }
    std::cout<<"Could not add node";
    try {
        throw 20;
    } catch (int e) {
        std::cout<<"Could not add node '"<<getValue()<<"' ";
    }
    return -1;
}
//Standard constructors of specialized Nodes

Compound::Compound(int num) : Node(num + 2, "<compound>") {

    _children[0] = new Node(0, "{\n");
    _children[num + 1] = new Node(0, "\n}\n");
    _numChildren = 2;

}

Statement::Statement(std::string var,std::string mid, const Expression& exp) : Node(3, "<statement>") {
    _children[0] = new Node(0, var);
    _children[1] = new Node(0, mid);
    _children[2] = new Expression(exp);
    _numChildren = 3;
}

If::If(const Expression& ex, const Compound& tru, const Compound& fals) : Node(4, "if") {
    _children[0] = new Expression(ex);
    _children[1] = new Compound(tru);
    _children[2] = new Node(0, "else ");
    _children[3] = new Compound(fals);
    _numChildren = 4;
}

Expression::Expression(std::string lhs) : Node(1, "<expression>") {
    _children[0] = new Node(0, lhs+"\n");
    _numChildren = 1;
}

Expression::Expression(std::string lhs, std::string mid) : Node(2, "<expression>") {
    _children[0] = new Node(0, lhs);
    _children[1] = new Node(0, mid);
    _numChildren = 2;
}

Expression::Expression(std::string lhs, std::string mid, std::string rhs) : Node(3, "<expression>") {
    _children[0] = new Node(0, lhs);
    _children[1] = new Node(0, mid);
    _children[2] = new Node(0, rhs);
    _numChildren = 3;
}

Expression::Expression(const Expression& exp, int dummy) : Node(3, "<expression>") {
    _children[0] = new Node(0, "(");
    _children[1] = new Expression(exp);
    _children[2] = new Node(0, ")");
    _numChildren = 3;
}

Expression::Expression(const Expression& lhs, std::string mid, std::string rhs) : Node(3, "<expression>") {
    _children[0] = new Expression(lhs);
    _children[1] = new Node(0, mid);
    _children[2] = new Node(0, rhs);
    _numChildren = 3;
}

Expression::Expression(const Expression& lhs, std::string mid, const Expression& rhs) : Node(3, "<expression>") {
    _children[0] = new Expression(lhs);
    _children[1] = new Node(0, mid);
    _children[2] = new Expression(rhs);
    _numChildren = 3;
}

Expression::Expression(std::string lhs, std::string mid, const Expression& rhs) : Node(3, "<expression>") {
    _children[0] = new Node(0, lhs);
    _children[2] = new Expression(rhs);
    _children[1] = new Node(0, mid);
    _numChildren = 3;
}

While::While(const Expression& exp, const Compound& comp) : Node(2, "while") {
    _children[0] = new Expression(exp);
    _children[1] = new Compound(comp);
    _numChildren = 2;
}

FunctionCall::FunctionCall(std::string var, int num) : Node(1 + num, "<functionCall>") {
    _children[0] = new Node(0, var + " ");
    _numChildren = 1;
}
//Destructors of special Nodes

Compound::~Compound() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }


    }
}

Statement::~Statement() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }


    }
}

Expression::~Expression() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }
    }
}

If::~If() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }


    }
}

While::~While() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }


    }
}

FunctionCall::~FunctionCall() {
    //  std::cout<<"Trying to delete node: "+_value<<" "<<this<<std::endl;
    for (int i = 0; i < _maxChildren; i++) {
        if (_children[i] != nullptr) {
            //       std::cout<<"Trying to delete node: "+_value<<" Child "<<i<<" "<<_children[i]<<std::endl;
            delete _children[i];
            _children[i] = nullptr;
            _numChildren--;
        }


    }
}

Compound::Compound(const Compound& orig){
    _maxChildren=orig._maxChildren;
    _numChildren=orig._numChildren;
    _children=orig._children;
    _value=orig._value;
}

Compound::Compound(const Compound&& orig){
     _maxChildren=std::move(orig._maxChildren);
    _numChildren=std::move(orig._numChildren);
    _children=std::move(orig._children);
    _value=std::move(orig._value);
}

