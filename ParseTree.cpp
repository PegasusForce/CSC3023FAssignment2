/* 
 * File:   ParseTree.cpp
 * Author: khagendra
 * 
 * Created on 10 April 2014, 11:30 AM
 */

#include "ParseTree.h"
#include <sstream>
#include <ostream>
ParseTree::ParseTree() {
    //std::cout<<"Creating Tree: "<<this<<std::endl;
    root=nullptr;
}

ParseTree& ParseTree::operator=(const ParseTree& rhs){
    if(&rhs!=this){
        root=new Node(*rhs.root);
    }
    return *this;
}

ParseTree& ParseTree::operator=(ParseTree&& rhs){
    if(this!=&rhs){
        root=std::move(rhs.root);
    }
    rhs.root=nullptr;
}

Iterator ParseTree::insert(Iterator parent, const Node & child){
  
    
    if(begin()==end()){
        root= new Node(child);
        parent.node=root;
        return parent;
    }
    
                int index = parent.node->addChild(child);
		if(index!=-1){
                    Iterator* copy = new Iterator(parent);
                    state temp;
                    temp.parent=parent.node;
                    temp.index=index;//The parent will index the added child
                    copy->node=parent.node->getChild(index);
                    copy->stack.push(temp);
                    return *copy;//Note a copy of copy is returned, but copy is not deleted. Possibly deleted during destruction
                }else{
                    return parent;
                }
		
}
std::ostream& ParseTree::operator<<(std::ostream& lhs){
    Iterator it = begin();
    std::stringstream ss;
    while(it!=end()){
       (*it)->to_string(ss);
        ++it;
    }
    lhs<<ss;
    return lhs;
}

std::string ParseTree::print(){
    Iterator it = begin();
    std::stringstream ss;
    while(it!=end()){
       (*it)->to_string(ss);
        ++it;
    }
    return ss.str();
}

