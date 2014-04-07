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
}
//Copy assignment opperator
Node& Node::operator=(const Node& rhs) {
    if(this!=&rhs){
        _children=rhs._children;
        _value=rhs._value;
        _numChildren=rhs._numChildren;
    }

}
//Move assignment operator

Node& Node::operator=(const Node&& rhs) {
    if(this!=&rhs){
        _children=std::move(rhs._children);
        _value=std::move(rhs._value);
        _numChildren=std::move(rhs._numChildren);
    }
}


