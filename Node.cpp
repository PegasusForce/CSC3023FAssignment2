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

Node::~Node() {
    
    for(int i=0;i<_maxChildren;i++){
        if(_children[i]!=nullptr){
            std::cout<<"Trying to delete node: "+_value<<"Child "<<i<<std::endl;
        delete _children[i];
        _children[i]=nullptr;
        }
        _children=nullptr;
        
    }
    
}
//Copy assignment operator
Node& Node::operator=(const Node& rhs) {
    if(this!=&rhs){
        _children=rhs._children;
        _value=rhs._value;
        _numChildren=rhs._numChildren;
        _maxChildren=rhs._maxChildren;
    }
    return *this;
}
//Move assignment operator

Node& Node::operator=(Node&& rhs) {
    if(this!=&rhs){
        _children=std::move(rhs._children);
        _value=std::move(rhs._value);
        _numChildren=std::move(rhs._numChildren);
        _maxChildren=std::move(rhs._maxChildren);
        rhs._children=nullptr;
    }
    return *this;
}

    void Node::to_string(std::stringstream& ss){
        if(_numChildren==0){
            ss << _value;
        }
    }
    
    Node::Node(int nc, std::string v){
        std::cout<<"Creating Node: "<<v<<std::endl;
        _maxChildren=nc;
        //Node* temp[nc];
        _children = new Node*[nc];
        for(int i=0;i<nc;i++){
            _children[i]=nullptr;
        }
        _value=v;
    }
    
    int Node::getNumChildren(){
        return _numChildren;
    }
    
    int Node::getMaxChildren(){
        return _maxChildren;
    }
    
    Node* Node::getChild(int i){
        if(i>=0&&i<_numChildren){
            return _children[i];
        }else{
            return nullptr;
        }
    }
    
     int Node::addChild(Node* child){
         for(int i=0;i<_maxChildren;i++){
             if(_children[i]==nullptr){
                 _children[i]=child;
                 _numChildren++;
                 return i;
             }
         }
         try{
             throw 20; 
         }catch(int e){
             std::cout<<"Could not add node '"+child->_value+"', parent full.";
         }
         return -1;
     }


