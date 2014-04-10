/* 
 * File:   Iterator.cpp
 * Author: khagendra
 * 
 * Created on 09 April 2014, 4:22 PM
 */

#include "Iterator.h"

Iterator::Iterator() {
}

Iterator::Iterator(Node* position){
    node = position;
    state parent = {nullptr,0};
    stack.push(parent);
}

Iterator::~Iterator() {
    
}

Iterator& Iterator::operator++(){
    if(node!=nullptr && node->getNumChildren()>0){
        state temp = {node,i};
        stack.push(temp);
        node=node->getChild(0);
    }else{
        state temp;
        while(true){
        temp = stack.top();
        if(temp.parent==nullptr){
            node=nullptr;
            break;
        }
       if(temp.index+1<temp.parent->getMaxChildren()){
            temp.index++;
       
            node=temp.parent->getChild(temp.index);
            
            break;
        }else{
            stack.pop();
        }
    }
}
    return *this;
}

Iterator& Iterator::operator+(std::size_t distance){
   
    for(int i=0;i<distance;i++){
        operator++();
    }
    return *this;
}
Iterator& Iterator::operator--(){
    if(node!=nullptr && node->getNumChildren()>0){
        state temp = {node,i};
        stack.push(temp);
        node=node->getChild(node->getMaxChildren()-1);
    }else{
        state temp;
        while(true){
        temp = stack.top();
        if(temp.parent==nullptr){
            node=nullptr;
            break;
        }
       if(temp.index>0){
            temp.index--;          
            node=temp.parent->getChild(temp.index);
            
            break;
        }else{
            stack.pop();
        }
    }
}
    return *this;
}
Iterator& Iterator::operator-(std::size_t distance){
   
    for(int i=0;i<distance;i++){
        operator--();
    }
    return *this;
}

std::size_t Iterator::operator-(const Iterator prev){
    size_t distance=0;
    Iterator temp = *this;
    while(true){
        if(*this==prev){
            return distance;
        }else{
            distance++;
           --temp;
        }
    }
}