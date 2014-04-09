/* 
 * File:   Iterator.cpp
 * Author: khagendra
 * 
 * Created on 09 April 2014, 4:22 PM
 */

#include "Iterator.h"

Iterator::Iterator() {
}

Iterator::~Iterator() {
}
Node& Iterator::operator++(){
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
            temp.index++;
            node=temp.parent->getChild(temp.index);
            
            break;
        }else{
            stack.pop();
        }
    }
}
}