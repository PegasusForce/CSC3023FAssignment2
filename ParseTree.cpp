/* 
 * File:   ParseTree.cpp
 * Author: khagendra
 * 
 * Created on 10 April 2014, 11:30 AM
 */

#include "ParseTree.h"

ParseTree::ParseTree() {
}

ParseTree& ParseTree::operator=(const ParseTree& rhs){
    if(&rhs!=this){
        root=rhs.root;
    }
    return *this;
}

ParseTree& ParseTree::operator=(ParseTree&& rhs){
    if(this!=&rhs){
        root=std::move(rhs.root);
    }
    rhs.root=nullptr;
}

Iterator insert(Iterator parent, const Node & child){
    
}



