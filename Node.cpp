/* 
 * File:   Node.cpp
 * Author: khagendra
 * 
 * Created on 07 April 2014, 8:54 PM
 */

#include "Node.h"

Node::Node() {
}

Node::~Node() {
    for(int i=0;i<_numChildren;i++){
        if(*(_children+i)!=nullptr){
        delete *(_children+i);
        }
        _children=nullptr;
    }
    
}
//Copy assignment opperator
Node& Node::operator=(const Node& rhs) {
    if(this!=&rhs){
        _children=rhs._children;
        _value=rhs._value;
        _numChildren=rhs._numChildren;
        _maxChildren=rhs._maxChildren;
    }

}
//Move assignment operator

Node& Node::operator=(const Node&& rhs) {
    if(this!=&rhs){
        _children=std::move(rhs._children);
        _value=std::move(rhs._value);
        _numChildren=std::move(rhs._numChildren);
        _maxChildren=std::move(rhs._maxChildren);
    }
}

    virtual void Node::to_string(std::stringstream ss){
        if(_numChildren==0){
            ss << _value;
        }
    }
    
    Node::Node(int nc){
        _maxChildren=nc;
    }
    


