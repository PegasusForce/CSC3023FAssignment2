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

Iterator ParseTree::insert(Iterator& parent, const Node & child){
  //  Iterator current = Iterator(root);
//		while(parent!=current){
//			++current;
//		}
    Node node = Node(child);
    if(begin()==end()){
        root=&node;
        return Iterator(&node);
    }
    
                int index = parent.node->addChild(&node);
		if(index!=-1){
                    Iterator copy = Iterator(parent);
                    state temp;
                    temp.parent=parent.node;
                    temp.index=index;//The parent will index the added child
                    copy.node=&node;
                    copy.stack.push(temp);
                    return copy;
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



